#!bin/bash
#script.sh
archivo=$1
clave="sorpresa"

Debug/CriptoTPE -out $1_des_des_ecb.wav -in $archivo -d -pass $clave   -a des -m ecb
Debug/CriptoTPE -out $1_des_aes128_ecb.wav -in $archivo -d -pass $clave   -a aes128 -m ecb
Debug/CriptoTPE -out $1_des_aes192_ecb.wav -in $archivo -d -pass $clave   -a aes192 -m ecb
Debug/CriptoTPE -out $1_des_aes256_ecb.wav -in $archivo -d -pass $clave   -a aes256 -m ecb

Debug/CriptoTPE -out $1_des_des_cfb.wav -in $archivo -d -pass $clave   -a des -m cfb
Debug/CriptoTPE -out $1_des_aes128_cfb.wav -in $archivo -d -pass $clave   -a aes128 -m cfb
Debug/CriptoTPE -out $1_des_aes192_cfb.wav -in $archivo -d -pass $clave   -a aes192 -m cfb
Debug/CriptoTPE -out $1_des_aes256_cfb.wav -in $archivo -d -pass $clave   -a aes256 -m cfb


Debug/CriptoTPE -out $1_des_des_ofb.wav -in $archivo -d -pass $clave   -a des -m ofb
Debug/CriptoTPE -out $1_des_aes128_ofb.wav -in $archivo -d -pass $clave   -a aes128 -m ofb
Debug/CriptoTPE -out $1_des_aes192_ofb.wav -in $archivo -d -pass $clave   -a aes192 -m ofb
Debug/CriptoTPE -out $1_des_aes256_ofb.wav -in $archivo -d -pass $clave   -a aes256 -m ofb


Debug/CriptoTPE -out $1_des_des_cbc.wav -in $archivo -d -pass $clave   -a des -m cbc
Debug/CriptoTPE -out $1_des_aes128_cbc.wav -in $archivo -d -pass $clave   -a aes128 -m cbc
Debug/CriptoTPE -out $1_des_aes192_cbc.wav -in $archivo -d -pass $clave   -a aes192 -m cbc
Debug/CriptoTPE -out $1_des_aes256_cbc.wav -in $archivo -d -pass $clave   -a aes256 -m cbc
