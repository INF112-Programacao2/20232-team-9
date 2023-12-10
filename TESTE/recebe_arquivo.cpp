#include <iostream>
#include <sstream>
#include <fstream>
#include <bits/stdc++.h>
#include "recebe_arquivo.h"
#include "pessoa.h"
#include "pessoajuridica.h"
#include "contabilidade_fisica.h"
#include "contabilidade_juridica.h"
#include "juridica_comercial.h"
#include "juridica_industrial.h"
#include "juridica_prestservico.h"

void RecebeArquivo::recebe_dados_fisico(ContabilFisica &dados, Pessoa &fisico){
    std::fstream out("Usuarios_Fisico.csv", std::ios::out | std::ios::app);
    out << fisico.get_cpf() << "," << fisico.get_nomepessoa() << std::endl;
    out << "Salario" << "," << dados.get_salario_bruto() << std::endl;
    out << "INSS" << "," << dados.get_inss() << std::endl;
    out << "Dependente" << "," << dados.get_deducao_dependente() <<std::endl;
    out << "Base" << "," << dados.get_base_calculo() << std::endl;
    out << "Aliquota" << "," << dados.get_aliquota() << std::endl;
    out << "Imposto de Renda" << "," << dados.get_imposto_dados() << std::endl;
    out.close();
}

void RecebeArquivo::recebe_dados_industrial(JuridicaIndustrial &dados, PessoaJuridica &juridico){
    std::vector<std::pair <std::string, double>> aux;
    aux = dados.get_contasPagar_dados();
    std::fstream out("Usuarios_Juridico_Industrial.csv", std::ios::out | std::ios::app);
    out << juridico.get_cpf() << "," << juridico.get_nomepessoa() << std::endl;

    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;

    aux = dados.get_contasReceber_dados();

    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;


    aux = dados.get_realizavelCurtoPrazo_dados();
    
    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;

    aux = dados.get_realizavelLongoPrazo_dados();

    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;

    aux = dados.get_emprestimos_dados();

    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;
}

void RecebeArquivo::recebe_dados_comercial(JuridicaComercial &dados, PessoaJuridica &juridico){
    std::vector<std::pair <std::string, double>> aux;
    aux = dados.get_contasPagar_dados();
    std::fstream out("Usuarios_Juridico_Comercial.csv", std::ios::out | std::ios::app);
    out << juridico.get_cpf() << "," << juridico.get_nomepessoa() << std::endl;

    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;

    aux = dados.get_contasReceber_dados();

    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;


    aux = dados.get_realizavelCurtoPrazo_dados();
    
    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;

    aux = dados.get_realizavelLongoPrazo_dados();

    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;

    aux = dados.get_emprestimos_dados();

    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;
}

void RecebeArquivo::recebe_dados_prestservico(JuridicaPrestServi &dados, PessoaJuridica &juridico){
    std::vector<std::pair <std::string, double>> aux;
    aux = dados.get_contasPagar_dados();
    std::fstream out("Usuarios_Juridico_Prestacao_de_Servico.csv", std::ios::out | std::ios::app);
    out << juridico.get_cpf() << "," << juridico.get_nomepessoa() << std::endl;

    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;

    aux = dados.get_contasReceber_dados();

    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;


    aux = dados.get_realizavelCurtoPrazo_dados();
    
    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;

    aux = dados.get_realizavelLongoPrazo_dados();

    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;

    aux = dados.get_emprestimos_dados();

    for(int i = 0; i < aux.size(); i++){
        out << aux[i].first << "," << aux[i].second << ",";
    }
    out << std::endl;
}

