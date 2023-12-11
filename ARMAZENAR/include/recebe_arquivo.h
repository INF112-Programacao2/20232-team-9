#ifndef _ARQUIVO_H
#define _ARQUIVO_H
#include <bits/stdc++.h>
#include "contabilidade_fisica.h"
#include "contabilidade_juridica.h"
#include "pessoa.h"
#include "pessoajuridica.h"
#include "juridica_industrial.h"
#include "juridica_comercial.h"
#include "juridica_prestservico.h"



class RecebeArquivo{
    public:
        void recebe_dados_fisico(ContabilFisica &dados, Pessoa &fisico);
        void recebe_dados_industrial(JuridicaIndustrial &dados, PessoaJuridica &juridico);
        void recebe_dados_prestservico(JuridicaPrestServi &dados, PessoaJuridica &juridico);
        void recebe_dados_comercial(JuridicaComercial &dados, PessoaJuridica &juridico);
        double retorna_receita_bruta(std::string cpf);
};

#endif