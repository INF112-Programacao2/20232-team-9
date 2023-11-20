#ifndef CONTABILIDADE_JURIDICA_H
#define CONTABILIDADE_JURIDICA_H

#include "cadastro.h"
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

class ContabilJuridica : public Cadastro{
	protected:
		std::vector<double> _caixa;
		std::vector<std::pair<const char*,int>> _estoque;
		std::vector<std::pair<const char*,double>> _contasReceber;
		std::vector<std::pair<const char*,int>> _realizavelLongoPrazo;
		std::vector<std::pair<const char*,int>> _realizavelCurtoPrazo;
		std::vector<std::pair<const char*,double>> _emprestimos;
		std::vector<std::pair<const char*,double>> _contasPagar;
		std::vector<int> _receitas;
		std::vector<int> _despesas;
		std::vector<int> _result_dre;

	public:
		//SET
		
		//ATIVO CIRCULANTE
		virtual void set_caixa(int quant_elementos);
		void set_estoque(int quant_elementos);
		virtual void set_contasReceber(int quant_elementos);

		//ATIVO NÃO CIRCULANTE
		virtual void set_realizavelLongoPrazo(int quant_elementos);
		
		//PASSIVO CIRCULANTE 
		virtual void set_realizavelCurtoPrazo(int quant_elementos);

		//PASSIVO NÃO CIRCULANTE
		virtual void set_emprestimos(int quant_elementos);
		virtual void set_contasPagar(int quant_elementos);

		//GET

		//ATIVO CIRCULANTE
		virtual double get_caixa();
		int get_estoque();
		virtual double get_contasReceber();

		//ATIVO NÃO CIRCULANTE
		virtual int get_realizavelLongoPrazo();

		//PASSIVO CIRCULANTE
		virtual int get_realizavelCurtoPrazo();

		//PASSIVO NÃO CIRCULANTE
		virtual double get_emprestimos();
		virtual double get_contasPagar();

		//METODOS
		void _calculo_DRE();
		void _calculo_fluxo_caixa();
		void _resultado_balancete();
		void _calculo_aliquotas();
		void _calculo_CNAE();
		 
};


#endif // CONTABILIDADE_JURIDICA_H