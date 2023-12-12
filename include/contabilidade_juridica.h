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
		long double _result_dre;
		long double _receita_bruta;
		long double _despesa;
		long double _resultado_fluxo_caixa;
		std::string _mes_contabil;
		int _ano_contabil;
		long double _lucro;



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
		
		//MẼS E ANO DA CONTABILIDADE FEITA
		void set_mes_contabil(); // seta o mês contábil
		void set_ano_contabil(); // seta o ano contábil

		//GET

		//ATIVO CIRCULANTE
		long double get_caixa(); // retorna o valor total do caixa
		long double get_contasReceber(); // retorna o valor total das contas a receber
		std::vector<std::pair<std::string, double>> get_contasReceber_dados(); // retorna a lista das contas a receber

		//ATIVO NÃO CIRCULANTE
		long double get_realizavelLongoPrazo(); // retorna o valor total dos realizaveis a longo prazo
		std::vector<std::pair<std::string, double>> get_realizavelLongoPrazo_dados(); // retorna a lista dos realizaveis a longo prazo

		//PASSIVO CIRCULANTE
		long double get_realizavelCurtoPrazo(); // retorna o valor total dos realizaveis a curto prazo
		std::vector<std::pair<std::string, double>> get_realizavelCurtoPrazo_dados(); // retorna a lista dos realizaveis a curto prazo

		//PASSIVO NÃO CIRCULANTE
		long double get_emprestimos(); // retorna o valor total de emprestimos
		std::vector<std::pair<std::string, double>> get_emprestimos_dados(); // retorna a lista dos emprestimos
		long double get_contasPagar(); // retorna o valor total de contas a pagar
		std::vector<std::pair<std::string, double>> get_contasPagar_dados(); // retorna a lista das contas a pagar

		//MẼS E ANO DA CONTABILIDADE FEITA
		std::string get_mes_contabil(); // retorna o mês contábil
		int get_ano_contabil(); // retorna o ano contábil

		//GETS DE RECEITA E DESPESA
		long double get_despesa(); // retorna o valor total das despesas
		long double get_lucro(); // retorna o valor total do lucro
		long double get_receita_bruta(); // retorna o valor da receita bruta (contribui no cálculo do simples nacional)

		//METODOS
		void _calculo_DRE(); // cálcula a Demonstração do Resultado do Exercício
		void _calculo_fluxo_caixa(); // cálcula o fluxo de caixa
		void _resultado_balancete(); // cálcula o balancete
		virtual void _calculo_aliquotas_anexos(std::string cpf) = 0; // cálcula as alíquotas de acordo com o anexo
		virtual double get_result_simples_nacional() = 0; // retorna o valor a ser pago ou restituído


		//LIMPEZA
		void _limpa_vectors(); // limpa o caixa
		 
};
#endif