#include <iostream>
#include <cstring>
#include "cadastro.h"


Cadastro::Cadastro(std::string nomepessoa, std::string nomeempresa, std::string apelidoempresa, std::string local):

_nomepessoa(nomepessoa), _nomeempresa (nomeempresa), _apelidoempresa (apelidoempresa), _local(local) {}



Cadastro::Cadastro (std::string nomepessoa, std::string local):

_nomepessoa(nomepessoa), _local(local) {}



void Cadastro::confere_cpf (std::string cpf) {

    int cont=1;
    int contnotdigit;

    _cpf=cpf;


    while (cont>0){

      contnotdigit=0;

     if(_cpf.size()<11 || _cpf.size()>11){

         std::cout<<"CPF Inválido!! Digite um novo CPF válido:"<<std::endl;
     
     }



     else{

       for(int i=0; _cpf[i] != '\0'; i++){

          if (!isdigit (_cpf[i])){
            contnotdigit++;
         }

       }


       if(contnotdigit>0){

         std::cout<<"CPF Inválido!! Digite um novo CPF válido:"<<std::endl;

        }


        else{

          break;

        }

    }  

      std::cin>>_cpf;

  }

}


void Cadastro::confere_cnpj (std::string cnpj){

    int cont=1;
    int contnotdigit;

    _cnpj=cnpj;


    while (cont>0){

      contnotdigit=0;

     if(_cnpj.size()<14 || _cnpj.size()>14){

         std::cout<<"CNPJ Inválido!! Digite um novo CNPJ válido:"<<std::endl;
     
     }



     else{

       for(int i=0; _cnpj[i] != '\0'; i++){

          if (!isdigit (_cnpj[i])){
            contnotdigit++;
         }

       }


       if(contnotdigit>0){

         std::cout<<"CNPJ Inválido!! Digite um novo CNPJ válido:"<<std::endl;

        }


        else{

          break;

        }

    }  

      std::cin>>_cnpj;

  }


}



std::string Cadastro::get_nomepessoa (){

    return _nomepessoa;

}


std::string Cadastro::get_nomeempresa (){

    return _nomeempresa;

}


std::string Cadastro::get_apelidoempresa(){

    return _apelidoempresa;

}


std::string Cadastro::get_cnpj(){

    return _cnpj;

}


std::string Cadastro::get_cpf(){

    return _cpf;

}


std::string Cadastro::get_local(){

    return _local;

}


void Cadastro::set_nomepessoa (std::string nomepessoa){

    _nomepessoa = nomepessoa;

}


void Cadastro::set_nomeempresa (std::string nomeempresa){

    _nomeempresa = nomeempresa;

}

void Cadastro::set_apelidoempresa (std::string apelidoempresa){

    _apelidoempresa = apelidoempresa;

}

void Cadastro::set_local (std::string local){

    _local = local;

}

