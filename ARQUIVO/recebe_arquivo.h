#ifndef _ARQUIVO_H
#define _ARQUIVO_H
#include <bits/stdc++.h>
#include "contabilidade_fisica.h"
#include "contabilidade_juridica.h"
#include "pessoa.h"
#include "pessoajuridica.h"
#include "juridica_industrial.h"




class RecebeArquivo{
    public:
        void recebe_dados_fisico(ContabilFisica &dados);
        void recebe_dados_industrial(JuridicaIndustrial &dados);
};

#endif