#include <openssl/evp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

/**
 * Project includes
 */

#include "../include/dataall.h"

/**
 * Se definen las funciones de cifrado.
 * DES(cbc,cfb9,ecb,ofb)
 * AES128(cbc,cfb9,ecb,ofb)
 * AES192(cbc,cfb9,ecb,ofb)
 * AES256(cbc,cfb9,ecb,ofb)
 * va a ser un arreglo del tipo funcionesDeCifrado_t que son punteros a funcion
 */
typedef const EVP_CIPHER* (*funcionesDeCifrado_t)(void);

const static funcionesDeCifrado_t ciperFunc[4][4] =
		{ { EVP_des_cbc, EVP_des_cfb8, EVP_des_ecb, EVP_des_ofb },
		  {	EVP_aes_128_cbc, EVP_aes_128_cfb8, EVP_aes_128_ecb,	EVP_aes_128_ofb },
		  { EVP_aes_192_cbc, EVP_aes_192_cfb8,EVP_aes_192_ecb, EVP_aes_192_ofb },
		  { EVP_aes_256_cbc,EVP_aes_256_cfb8, EVP_aes_256_ecb, EVP_aes_256_ofb } };

static funcionesDeCifrado_t getCipherFunc(encModeT blockEnc, primitiveT prim) {
	return ciperFunc[prim][blockEnc];
}
void hasPassPass() {
	data* pdata;
	pdata = getdata();
	/*printf("indice modo = %d , indice funcion = %d\n", pdata->enc_mode, pdata->primitive);*/
	funcionesDeCifrado_t func =
			getCipherFunc(pdata->enc_mode, pdata->primitive);
	if (pdata->pass[0] != '\0') {
		EVP_BytesToKey(func(), EVP_md5(), NULL, pdata->pass,
				strlen(pdata->pass), 1, pdata->key, pdata->vector);
	}
}
wave *
cipher(wave * waveFile, data* dataCypherInfo) {

	unsigned char *in;
	unsigned char *out;
	int inl, outl, templ;
	unsigned char k[LINE]; /*= "0123456789012345 128 bits = 16 bytes*/
	unsigned char iv[LINE];/*= "5432109876543210"/*/
	;

	EVP_CIPHER_CTX ctx;

	inl = waveFile->cantBits;
	in = calloc(waveFile->cantBits, 1);
	memcpy(in, waveFile->bits,waveFile->cantBits);
	out = (unsigned char*) malloc(inl + 500);

	printf("tengo %d bytes \n ", inl);
	funcionesDeCifrado_t func = getCipherFunc(dataCypherInfo->enc_mode,
			dataCypherInfo->primitive);
	/*Init Context*/

	memcpy(k, dataCypherInfo->key,strlen(dataCypherInfo->key));
	memcpy(iv, dataCypherInfo->vector,strlen(dataCypherInfo->vector));

	EVP_CIPHER_CTX_init(&ctx);

	/*Encryption parameters, this should be dinamyc*/
	EVP_EncryptInit_ex(&ctx, func(), NULL, k, iv);

	EVP_EncryptUpdate(&ctx, out, &outl, in, inl); /* Encripta 112 */

	/* Encripta la parte final, lo que queda del bloque + padding, en este caso 4 bytes + 12 bytes de padding */
	EVP_EncryptFinal(&ctx, out + outl, &templ);
	/*últimos 16 bytes*/

	/* Borrar estructura de contexto */
	EVP_CIPHER_CTX_cleanup(&ctx);
	memcpy(waveFile->bits,out,outl + templ);
	free(out);
	free(in);
	waveFile->cantBits = outl + templ;
	return EXIT_SUCCESS;
}
int uncipher(wave * waveFile, data* dataCypherInfo) {
	unsigned char *in;
	unsigned char *out;
	int inl, outl, templ;
	unsigned char k[LINE]; /*= "0123456789012345 128 bits = 16 bytes*/
	unsigned char iv[LINE];/*= "5432109876543210"/*/
	;

	EVP_CIPHER_CTX ctx;

	inl = waveFile->cantBits;
	in = calloc(waveFile->cantBits, 1);
	memcpy(in, waveFile->bits,waveFile->cantBits);
	out = (unsigned char*) malloc(inl + 500);

	funcionesDeCifrado_t func = getCipherFunc(dataCypherInfo->enc_mode,
			dataCypherInfo->primitive);
	/*Init Context*/

	memcpy(k, dataCypherInfo->key,strlen(dataCypherInfo->key));
	memcpy(iv, dataCypherInfo->vector,strlen(dataCypherInfo->vector));

	/*Init Context*/
	EVP_CIPHER_CTX_init(&ctx);

	/*Encryption parameters, this should be dinamyc*/
	EVP_DecryptInit_ex(&ctx, func(), NULL, k, iv);

	EVP_DecryptUpdate(&ctx, out, &outl, in, inl); /* Encripta 112 */

	/* Encripta la parte final, lo que queda del bloque + padding, en este caso 4 bytes + 12 bytes de padding */
	EVP_DecryptFinal_ex(&ctx, out + outl, &templ);

	/*últimos 16 bytes*/
	/* Borrar estructura de contexto */
	EVP_CIPHER_CTX_cleanup(&ctx);
	memcpy(waveFile->bits,out,outl + templ);
	free(out);
	waveFile->cantBits = outl + templ;
	return EXIT_SUCCESS;

}

