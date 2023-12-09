#ifndef CONTABIL_JURIDICA_H
#define CONTABIL_JURIDICA_H
#include "pessoajuridica.h"
#include "pessoa.h"
#include <bits/stdc++.h>
// tributação federal:
// tributação estadual:
// tributação por municipio:
// CNAE sob tipo de empresa (qual atuação no ramo)
// Razão social : nome da empresa
// apelido : nome fantasia
// NATUREZA JURIDICA (ja vem no cnpj)
// IPI (depende do ramo)
// Verificar se tem matriz, filial ou franquia
// dados basicos sobre a empresa
// PLANOS DE CONTAS PARA CADA MODELO DE NEGÓCIO
// PLANO DE CONTAS É O BALANÇO
// BALANÇO (feito após feito plano de contas, podendo ser mensal, trimestral, semestral ou anual)
// o balanço será feito com  vetores (para guardar datas) com double (dinheiro) e deve ser fechado (as contas devem bater)
//  a tributação é totalmente feita pelo CNAE
// LUCRO REAL, SIMPLES NACIONAL, MICROEMPRESA, ETC (formas de tributação)

//------------------------------------------------------------------------------------

//CLASSE INTERFACE PARA CONTABILIDADE JURIDICA

class ContabilJuridica {
	private:
		std::vector<int> _caixa;
		std::vector<std::pair<std::string, double>> _contasPagar; //CÁCULO DRE
		std::vector<std::pair<std::string, double>> _contasReceber; //CÁLCULO DRE
		std::vector<std::pair<std::string, double>> _realizavelLongoPrazo; //CÁLCULO BALANCETE
		std::vector<std::pair<std::string, double>> _realizavelCurtoPrazo; 
		std::vector<std::pair<std::string, double>> _emprestimos;
		std::vector<int> _receitas;
		std::vector<int> _despesas;
		std::vector<int> _result_dre;
		double _receita_bruta;
		double _resultado_fluxo_caixa;



	public:
		//SET
		
		//ATIVO CIRCULANTE
		void set_caixa(); // seta o valor do caixa
		void set_contasReceber(); // seta a lista e o valor das contas a receber

		//ATIVO NÃO CIRCULANTE
		void set_realizavelLongoPrazo(); // seta a lista e o valor dos realizaveis a longo prazo

		//PASSIVO CIRCULANTE
		void set_realizavelCurtoPrazo(); // seta a lista e o valor dos realizaveis a curto prazo

		//PASSIVO NÃO CIRCULANTE
		void set_emprestimos(); // seta a lista e o valor dos emprestimos
		void set_contasPagar(); // seta a lista e o valor das contas a pagar

		//GET

		//ATIVO CIRCULANTE
		double get_caixa(); // retorna o valor total do caixa
		int get_estoque(); // retorna o valor total do estoque
		double get_contasReceber(); // retorna o valor total das contas a receber

		//ATIVO NÃO CIRCULANTE
		int get_realizavelLongoPrazo(); // retorna o valor total dos realizaveis a longo prazo

		//PASSIVO CIRCULANTE
		int get_realizavelCurtoPrazo(); // retorna o valor total dos realizaveis a curto prazo

		//PASSIVO NÃO CIRCULANTE
		double get_emprestimos(); // retorna o valor total de emprestimos
		double get_contasPagar(); // retorna o valor total de contas a pagar

		//METODOS
		void _calculo_DRE(); // cálcula a Demonstração do Resultado do Exercício
		void _calculo_fluxo_caixa(); // cálcula o fluxo de caixa
		void _resultado_balancete(); // cálcula o balancete
		/*void _calculo_aliquotas_localidade(PessoaJuridica &juridico);*/
		double get_receita_bruta(); // retorna o valor da receita bruta (contribui no cálculo do simples nacional)
		virtual void _calculo_aliquotas_anexos() = 0; // cálcula as alíquotas de acordo com o anexo
		virtual double get_result_simples_nacional() = 0; // retorna o valor a ser pago ou restituído
		 
};
#endif