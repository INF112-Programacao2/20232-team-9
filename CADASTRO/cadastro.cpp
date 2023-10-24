#include <iostream>
#include <cstring>
#include "cadastro.h"


Cadastro::Cadastro(char *nomepessoa, char *nomeempresa, char *apelidoempresa, char *local, char *cnpj){
    
    strcpy (_nomepessoa, nomepessoa);
    strcpy (_nomeempresa, nomeempresa);
    strcpy (_apelidoempresa, apelidoempresa);
    strcpy (_local, local);
    strcpy (_cnpj, cnpj);

}


Cadastro::Cadastro (char *nomepessoa, char *local, char *cpf){

    strcpy (_nomepessoa, nomepessoa);
    strcpy (_local, local);
    strcpy (_cpf, cpf);

}


char Cadastro::get_nomepessoa (){

    return *_nomepessoa;

}


char Cadastro::get_nomeempresa (){

    return *_nomeempresa;

}


char Cadastro::get_apelidoempresa(){

    return *_apelidoempresa;

}


char Cadastro::get_cnpj(){

    return *_cnpj;

}


char Cadastro::get_cpf(){

    return *_cpf;

}


char Cadastro::get_local(){

    return *_local;

}


void Cadastro::set_nomepessoa (char *nomepessoa){

    strcpy (_nomepessoa, nomepessoa);

}


void Cadastro::set_nomeempresa (char *nomeempresa){

    strcpy (_nomeempresa, nomeempresa);

}

void Cadastro::set_apelidoempresa (char *apelidoempresa){

    strcpy (_apelidoempresa, apelidoempresa);

}

void Cadastro::set_local (char *local){

    strcpy (_local, local);

}

void Cadastro::set_cpf (char *cpf){

    strcpy (_cpf, cpf);

}

void Cadastro::set_cnpj (char *cnpj){

    strcpy (_cnpj, cnpj);

}
