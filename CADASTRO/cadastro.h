class Cadastro{
 
 private:
  
  char _nomepessoa [50];
  char _nomeempresa [30];
  char _apelidoempresa [30];
  char _local [30];
  char _cpf [11];
  char _cnpj [14];

 
 
 public:

    Cadastro (char *nomepessoa, char *nomeempresa, char *apelidoempresa, char *local, char *cnpj);

    Cadastro (char *nomepessoa, char *local, char *cpf);

    char get_nomepessoa ();

    char get_nomeempresa ();

    char get_apelidoempresa ();

    char get_local ();

    char get_cpf ();

    char get_cnpj ();

    void set_nomepessoa (char *nomepessoa);

    void set_nomeempresa (char *nomeempresa);

    void set_apelidoempresa (char *apelidoempresa);

    void set_local (char *local);

    void set_cpf (char *cpf);

    void set_cnpj (char *cnpj);


};