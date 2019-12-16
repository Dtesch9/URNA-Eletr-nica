#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int cpf;
  int prefeito_vote;
  int vereador_vote;
} Candidato;

int Lucas = 0, Marcos = 0, nuloPrefeito = 0, nuloVereador = 0, brancoPrefeito = 0,
brancoVereador = 0, Douglas = 0, Tesch = 0, response = 0, prefeitoVerifyRes = 0, vereadorVerifyRes = 0;
int clone[50];


/* VOTOS INDIVIDUAIS */

void armazenaPartidoPrefeito(int Lucas, int Marcos, int nuloPrefeito, int brancoPrefeito) 
{
  float lucasPercent = 0;
  float marcosPercent = 0;
  float nuloPrefeitoPercent = 0;
  float brancoPrefeitoPercent = 0;
  int total = 0;

  total = Lucas + Marcos + nuloPrefeito + brancoPrefeito;
  lucasPercent = (Lucas * 100) / total;
  marcosPercent = (Marcos * 100) / total;
  nuloPrefeitoPercent = (nuloPrefeito * 100) / total;
  brancoPrefeitoPercent = (brancoPrefeito * 100) / total;

  FILE *partidoVoto;

  partidoVoto = fopen("qtdVotosPrefeito.txt", "w");

  if (partidoVoto == NULL)
  {
    printf("Error 404\n");
    return 0;
  }
  fprintf(partidoVoto, "===================== \n");
  fprintf(partidoVoto, "VOTAÇÃO PARA PREFEITO \n");
  fprintf(partidoVoto, "===================== \n");
  fprintf(partidoVoto, "Voto Lucas:%d - %.2f%\n", Lucas, lucasPercent);
  fprintf(partidoVoto, "Voto Marcos:%d - %.2f%\n", Marcos, marcosPercent);
  fprintf(partidoVoto, "Voto NULO:%d - %.2f%\n", nuloPrefeito, nuloPrefeitoPercent);
  fprintf(partidoVoto, "Voto BRANCO:%d - %.2f%\n", brancoPrefeito, brancoPrefeitoPercent);
  fclose(partidoVoto);
}

void armazenaPartidoVereador(int Douglas, int Tesch, int nuloVereador, int brancoVereador)
{
  float douglasPercent = 0;
  float teschPercent = 0;
  float nuloVereadorPercent = 0;
  float brancoVereadorPercent = 0;
  int total = 0;

  total = Douglas + Tesch + nuloVereador + brancoVereador;
  douglasPercent = (Douglas * 100) / total;
  teschPercent = (Tesch * 100) / total;
  nuloVereadorPercent = (nuloVereador * 100) / total;
  brancoVereadorPercent = (brancoVereador * 100) / total;

  FILE *partidoVoto;

  partidoVoto = fopen("qtdVotosVereador.txt", "w");

  if (partidoVoto == NULL)
  {
    printf("Error 404\n");
    return 0;
  }
  fprintf(partidoVoto, "===================== \n");
  fprintf(partidoVoto, "VOTAÇÃO PARA VEREADOR \n");
  fprintf(partidoVoto, "===================== \n");
  fprintf(partidoVoto, "Voto DOUGLAS:%d - %.2f%\n", Douglas, douglasPercent);
  fprintf(partidoVoto, "Voto TESCH:%d - %.2f%\n", Tesch, teschPercent);
  fprintf(partidoVoto, "Voto NULO:%d - %.2f%\n", nuloVereador, nuloVereadorPercent);
  fprintf(partidoVoto, "Voto BRANCO:%d - %.2f%\n", brancoVereador, brancoVereadorPercent);
  fclose(partidoVoto);
}

/* ARMAZENA CPFS E VOTOS DE CADA PESSOA */

void armazenaDadosVotePrefeito(Candidato *aux)
{
  FILE *file;

  file = fopen("votosParaPrefeito.txt", "a+");

  if (file == NULL)
  {
    printf("Error 404");
    return 0;
  }

  fprintf(file, "CPF:%d\n", aux->cpf);
  fprintf(file, "VOTO PARA PREFEITO:%d\n", (*aux).prefeito_vote);
  fprintf(file, "===================== \n");
  fclose(file);
}

void armazenaDadosVoteVereador(Candidato *candAux)
{
  FILE *file;

  file = fopen("votosParaVereador.txt", "a+");

  if (file == NULL)
  {
    printf("Error 404");
    return 0;
  }

  fprintf(file, "CPF:%d\n", candAux->cpf);
  fprintf(file, "VOTO PARA VEREADOR:%d\n", (*candAux).vereador_vote);
  fprintf(file, "===================== \n");
  fclose(file);
}

/* ARQUIVO SÓ DE CPFS */

void armazenaCPF(Candidato *auxCpf)
{
  FILE *file;

  file = fopen("cpfs.txt", "a+");

  if (file == NULL)
  {
    printf("Error 404");
    return 0;
  }

  fprintf(file, "%d\n", auxCpf->cpf);
  fclose(file);
}

/* ARQUIVOS SÓ DE VOTOS */

void armazenaVotoPrefeito(int Lucas, int Marcos, int nuloPrefeito, int brancoPrefeito)
{
  FILE *file;

  file = fopen("votosPrefeito.txt", "w");

  if (file == NULL)
  {
    printf("Error 404");
    return 0;
  }

  fprintf(file, "%d\n", Lucas);
  fprintf(file, "%d\n", Marcos);
  fprintf(file, "%d\n", nuloPrefeito);
  fprintf(file, "%d\n", brancoPrefeito);
  fclose(file);
}

void armazenaVotoVereador(int Douglas, int Tesch, int nuloVereador, int brancoVereador)
{
  FILE *file;

  file = fopen("votosVereador.txt", "w");

  if (file == NULL)
  {
    printf("Error 404");
    return 0;
  }

  fprintf(file, "%d\n", Douglas);
  fprintf(file, "%d\n", Tesch);
  fprintf(file, "%d\n", nuloVereador);
  fprintf(file, "%d\n", brancoVereador);
  fclose(file);
}

/* ============================================================================ */

/* =================== LOADS ==================== */
void cpfLoad() 
{
  int i = 0;
  FILE *readCpfs;

  readCpfs = fopen("cpfs.txt", "r");

  while ((fscanf(readCpfs, "%d\n", &clone[i])) != EOF)
  {
    i++;
  }
  fclose(readCpfs);
}

/* CARREGAMENTO DOS CPFS ANTES DA VOTAÇÃO */
void prefeitoVoteLoad()
{
  FILE *readPrefeitoVote;

  readPrefeitoVote = fopen("votosPrefeito.txt", "r");

  while ((fscanf(readPrefeitoVote, "%d %d %d %d\n", &Lucas, &Marcos, &nuloPrefeito, &brancoPrefeito)) != EOF)

  fclose(readPrefeitoVote);
}

/* CARREGAMENTO DOS CPFS ANTES DA VOTAÇÃO */
void vereadorVoteLoad()
{
  FILE *readVereadorVote;

  readVereadorVote = fopen("votosPrefeito.txt", "r");

  while ((fscanf(readVereadorVote, "%d %d %d %d\n", &Douglas, &Tesch, &nuloVereador, &brancoVereador)) != EOF)

    fclose(readVereadorVote);
}

/* ============================================================================ */

/* ===== ENTRADA DE DADOS PARA VOTAÇÃO ====== */

void vote()
{
  Candidato *cad = (Candidato *)malloc(sizeof(Candidato) * 100);
  __fpurge(stdin);
  printf("||================================================||\n");
  printf("||================Informe seu CPF=================||\n");
  printf("||================================================||\n");
  scanf("%d", &cad->cpf);
  system("clear");

  response = cloneCpf(cad);

  if (response == 0)
  {

    printf("||================================================||\n");
    printf("||==============Voto para prefeito================||\n");
    printf("||================================================||\n");
    printf("||Lucas - 14 | Marcos - 18 | 1 - NULO | 0 - BRANCO||\n");
    printf("||================================================||\n");
    scanf("%d", &cad->prefeito_vote);

    prefeitoVerifyRes = prefeitoVerify(cad);
    if (prefeitoVerifyRes == 0) 
    {
      printf("||================================================||\n");
      printf("||===============Voto para Vereador===============||\n");
      printf("||================================================||\n");
      printf("||Douglas - 9 | Tesch - 13 | 1 - NULO | 0 - BRANCO||\n");
      printf("||================================================||\n");
      scanf("%d", &cad->vereador_vote);
      system("clear");

      vereadorVerifyRes = vereadorVerify(cad);
      if (vereadorVerifyRes == 0)
      {
        prefeitoStorageVerify(cad);
        vereadorStorageVerify(cad);
      }
    }
  }
}

/* VERIFICA SE O CPF JÁ VOTOU */

int cloneCpf(Candidato *cloneCpf) {
  int res = 0, already = 0;
  for (int x = 0; x < 50; x++) {
    if (clone[x] == cloneCpf->cpf)
    {
      res = -1;
      already--;
      if (already == -1) {
        printf("||===================================================||\n");
        printf("||WARNING! Mesmo CPF NÃO pode votar mais de uma vez!!||\n");
        printf("||===================================================||\n");
      }
    }
  }
  return res;
}

/* VERIFICA SE O VOTO É VÁLIDO E CALCULA QTD DE VOTOS */

int prefeitoVerify(Candidato *test) {
  int res = 0;
  switch (test->prefeito_vote)
  {
  case 14:
    Lucas++;
    break;
  case 18:
    Marcos++;
    break;
  case 1:
    nuloPrefeito++;
    break;
  case 0:
    brancoPrefeito++;
    break;
  default:
    system("clear");
    printf("Voto inválido!\n");
    res--;
    break;
  }
  return res;
}

int vereadorVerify(Candidato *vereadorTest) {
  int res = 0;
  switch (vereadorTest->vereador_vote)
  {
  case 9:
    Douglas++;
    break;
  case 13:
    Tesch++;
    break;
  case 1:
    nuloVereador++;
    break;
  case 0:
    brancoVereador++;
    break;
  default:
    printf("Voto inválido!\n");
    res--;
    break;
  }
  return res;
}

/* ============================================================================ */

/* ARMAZENA O VOTO APENAS SE FOR VÁLIDO */

void prefeitoStorageVerify(Candidato *prefeitoStorageVerify) {
  if (prefeitoStorageVerify->prefeito_vote == 14 || prefeitoStorageVerify->prefeito_vote == 18 || prefeitoStorageVerify->prefeito_vote == 1 || prefeitoStorageVerify->prefeito_vote == 0)
  {
    armazenaDadosVotePrefeito(prefeitoStorageVerify);
    armazenaVotoPrefeito(Lucas, Marcos, nuloPrefeito, brancoPrefeito);
  }
  else
  {
    printf("Candidato não pode ser armazenado!\n");
  }
}

void vereadorStorageVerify(Candidato *vereadorStorageVerify) {
  if (vereadorStorageVerify->vereador_vote == 9 || vereadorStorageVerify->vereador_vote == 13 || vereadorStorageVerify->vereador_vote == 1 || vereadorStorageVerify->vereador_vote == 0)
  {
    armazenaDadosVoteVereador(vereadorStorageVerify);
    armazenaVotoVereador(Douglas, Tesch, nuloVereador, brancoVereador);
    armazenaCPF(vereadorStorageVerify);
  }
  else
  {
    printf("Candidato não pode ser armazenado!\n");
  }
}

/* ============================================================================ */

/* PRINTA OS RELATÓRIOS */

void mostraRelatorioPrefeito()
{
  char votosPrefeito[100];

  FILE *rFile;

  rFile = fopen("qtdVotosPrefeito.txt", "r");

  int x = 0;

  while (fgets(votosPrefeito, sizeof(votosPrefeito), rFile) != NULL)
  {
    printf("%s", votosPrefeito);
  }
  printf("\n");

  fclose(rFile);
}

void mostraRelatorioVereador()
{
  char votosVereador[100];

  FILE *rFile;

  rFile = fopen("qtdVotosVereador.txt", "r");

  int x = 0;

  while (fgets(votosVereador, sizeof(votosVereador), rFile) != NULL)
  {
    printf("%s", votosVereador);
  }

  fclose(rFile);
}

int main()
{
  int op = -1, menu = 1;

  printf("||================================================||\n");
  printf("||  1 - ENTRADA DE DADOS OU 0 - LEITURA DE DADOS  ||\n");
  printf("||================================================||\n");
  scanf("%d", &op);
  system("clear");

  if (op == 1)
  {   
    cpfLoad();
    prefeitoVoteLoad();
    vereadorVoteLoad();

        for (int i = 0; i < 100; i++)
    {
      printf("||===================================================||\n");
      printf("||=================Adicionar Votação=================||\n");
      printf("||==============|| 1 - SIM || 0 - NÃO ||=============||\n");
      printf("||===================================================||\n");
      scanf("%d", &menu);

      if (menu == 1)
      {

        vote();
        cpfLoad();
      } else if (menu == 0) {

        armazenaPartidoPrefeito(Lucas, Marcos, nuloPrefeito, brancoPrefeito);
        armazenaPartidoVereador(Douglas, Tesch, nuloVereador, brancoVereador);
        return 0;

      } else {
        system("clear");
        printf("||================================================||\n");
        printf("||===============||OPÇÃO INVÁLIDA||===============||\n");
        printf("||================================================||\n");
      }
    }
  }
  else
  {
    mostraRelatorioPrefeito();
    mostraRelatorioVereador();
  }

  return 0;
}