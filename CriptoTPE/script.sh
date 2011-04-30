#!bin/bash
#script.sh
clave="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
iv="1234567890"

Debug/CriptoTPE -in $1 -out $1_enc_des_ecb.wav -e -k $clave -iv $iv -a des -m ecb
Debug/CriptoTPE -in $1 -out $1_enc_aes128_ecb.wav -e -k $clave -iv $iv -a aes128 -m ecb
Debug/CriptoTPE -in $1 -out $1_enc_aes192_ecb.wav -e -k $clave -iv $iv -a aes192 -m ecb
Debug/CriptoTPE -in $1 -out $1_enc_aes256_ecb.wav -e -k $clave -iv $iv -a aes256 -m ecb

Debug/CriptoTPE -in $1 -out $1_enc_des_cfb.wav -e -k $clave -iv $iv -a des -m cfb
Debug/CriptoTPE -in $1 -out $1_enc_aes128_cfb.wav -e -k $clave -iv $iv -a aes128 -m cfb
Debug/CriptoTPE -in $1 -out $1_enc_aes192_cfb.wav -e -k $clave -iv $iv -a aes192 -m cfb
Debug/CriptoTPE -in $1 -out $1_enc_aes256_cfb.wav -e -k $clave -iv $iv -a aes256 -m cfb


Debug/CriptoTPE -in $1 -out $1_enc_des_ofb.wav -e -k $clave -iv $iv -a des -m ofb
Debug/CriptoTPE -in $1 -out $1_enc_aes128_ofb.wav -e -k $clave -iv $iv -a aes128 -m ofb
Debug/CriptoTPE -in $1 -out $1_enc_aes192_ofb.wav -e -k $clave -iv $iv -a aes192 -m ofb
Debug/CriptoTPE -in $1 -out $1_enc_aes256_ofb.wav -e -k $clave -iv $iv -a aes256 -m ofb


Debug/CriptoTPE -in $1 -out $1_enc_des_cbc.wav -e -k $clave -iv $iv -a des -m cbc
Debug/CriptoTPE -in $1 -out $1_enc_aes128_cbc.wav -e -k $clave -iv $iv -a aes128 -m cbc
Debug/CriptoTPE -in $1 -out $1_enc_aes192_cbc.wav -e -k $clave -iv $iv -a aes192 -m cbc
Debug/CriptoTPE -in $1 -out $1_enc_aes256_cbc.wav -e -k $clave -iv $iv -a aes256 -m cbc

##################################################################################################


Debug/CriptoTPE -out $1_des_des_ecb.wav -in $1_enc_des_ecb.wav -d -k $clave -iv $iv -a des -m ecb
Debug/CriptoTPE -out $1_des_aes128_ecb.wav -in $1_enc_aes128_ecb.wav -d -k $clave -iv $iv -a aes128 -m ecb
Debug/CriptoTPE -out $1_des_aes192_ecb.wav -in $1_enc_aes192_ecb.wav -d -k $clave -iv $iv -a aes192 -m ecb
Debug/CriptoTPE -out $1_des_aes256_ecb.wav -in $1_enc_aes256_ecb.wav -d -k $clave -iv $iv -a aes256 -m ecb

Debug/CriptoTPE -out $1_des_des_cfb.wav -in $1_enc_des_cfb.wav -d -k $clave -iv $iv -a des -m cfb
Debug/CriptoTPE -out $1_des_aes128_cfb.wav -in $1_enc_aes128_cfb.wav -d -k $clave -iv $iv -a aes128 -m cfb
Debug/CriptoTPE -out $1_des_aes192_cfb.wav -in $1_enc_aes192_cfb.wav -d -k $clave -iv $iv -a aes192 -m cfb
Debug/CriptoTPE -out $1_des_aes256_cfb.wav -in $1_enc_aes256_cfb.wav -d -k $clave -iv $iv -a aes256 -m cfb


Debug/CriptoTPE -out $1_des_des_ofb.wav -in $1_enc_des_ofb.wav -d -k $clave -iv $iv -a des -m ofb
Debug/CriptoTPE -out $1_des_aes128_ofb.wav -in $1_enc_aes128_ofb.wav -d -k $clave -iv $iv -a aes128 -m ofb
Debug/CriptoTPE -out $1_des_aes192_ofb.wav -in $1_enc_aes192_ofb.wav -d -k $clave -iv $iv -a aes192 -m ofb
Debug/CriptoTPE -out $1_des_aes256_ofb.wav -in $1_enc_aes256_ofb.wav -d -k $clave -iv $iv -a aes256 -m ofb


Debug/CriptoTPE -out $1_des_des_cbc.wav -in $1_enc_des_cbc.wav -d -k $clave -iv $iv -a des -m cbc
Debug/CriptoTPE -out $1_des_aes128_cbc.wav -in $1_enc_aes128_cbc.wav -d -k $clave -iv $iv -a aes128 -m cbc
Debug/CriptoTPE -out $1_des_aes192_cbc.wav -in $1_enc_aes192_cbc.wav -d -k $clave -iv $iv -a aes192 -m cbc
Debug/CriptoTPE -out $1_des_aes256_cbc.wav -in $1_enc_aes256_cbc.wav -d -k $clave -iv $iv -a aes256 -m cbc



#aes128|aes192|aes256|des>
#-m <ecb|cfb|ofb|cbc>
