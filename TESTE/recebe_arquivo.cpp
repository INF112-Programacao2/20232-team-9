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

void RecebeArquivo::recebe_dados_industrial(JuridicaIndustrial &dados){
    
}