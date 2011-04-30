#!bin/bash
#script.sh
archivo=$1
clave=$2
iv=$3

Debug/CriptoTPE -out $1_des_des_ecb.wav -in $archivo -d -k $clave -iv $iv -a des -m ecb
Debug/CriptoTPE -out $1_des_aes128_ecb.wav -in $archivo -d -k $clave -iv $iv -a aes128 -m ecb
Debug/CriptoTPE -out $1_des_aes192_ecb.wav -in $archivo -d -k $clave -iv $iv -a aes192 -m ecb
Debug/CriptoTPE -out $1_des_aes256_ecb.wav -in $archivo -d -k $clave -iv $iv -a aes256 -m ecb

Debug/CriptoTPE -out $1_des_des_cfb.wav -in $archivo -d -k $clave -iv $iv -a des -m cfb
Debug/CriptoTPE -out $1_des_aes128_cfb.wav -in $archivo -d -k $clave -iv $iv -a aes128 -m cfb
Debug/CriptoTPE -out $1_des_aes192_cfb.wav -in $archivo -d -k $clave -iv $iv -a aes192 -m cfb
Debug/CriptoTPE -out $1_des_aes256_cfb.wav -in $archivo -d -k $clave -iv $iv -a aes256 -m cfb


Debug/CriptoTPE -out $1_des_des_ofb.wav -in $archivo -d -k $clave -iv $iv -a des -m ofb
Debug/CriptoTPE -out $1_des_aes128_ofb.wav -in $archivo -d -k $clave -iv $iv -a aes128 -m ofb
Debug/CriptoTPE -out $1_des_aes192_ofb.wav -in $archivo -d -k $clave -iv $iv -a aes192 -m ofb
Debug/CriptoTPE -out $1_des_aes256_ofb.wav -in $archivo -d -k $clave -iv $iv -a aes256 -m ofb


Debug/CriptoTPE -out $1_des_des_cbc.wav -in $archivo -d -k $clave -iv $iv -a des -m cbc
Debug/CriptoTPE -out $1_des_aes128_cbc.wav -in $archivo -d -k $clave -iv $iv -a aes128 -m cbc
Debug/CriptoTPE -out $1_des_aes192_cbc.wav -in $archivo -d -k $clave -iv $iv -a aes192 -m cbc
Debug/CriptoTPE -out $1_des_aes256_cbc.wav -in $archivo -d -k $clave -iv $iv -a aes256 -m cbc
