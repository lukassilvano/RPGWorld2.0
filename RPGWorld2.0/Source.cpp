//OBSERVA��O: TEVE MUITA COISA QUE PRECISEI RETIRAR DEVIDO AO TEMPO COMO POR EXEMPLO 2 HIST�RIAS DIFERENTES, QUE IA SE
//PASSAR NO PRESENTE E NO FUTURO, AL�M DE MAIS ESCOLHAS NA �POCA MEDIEVAL, MAS DEVIDO AO TEMPO, PRECISEI REDUZIR AO M�XIMO
//A HIST�RIA DO JOGO, ENT�O ESPERO QUE O QUE TENHA SEJA SUFICIENTE.

//Eu tentei meio que fazer um livro de RPG, onde as suas escolhas te levam para caminhos diferente, s� que numa vers�o digital.
#include "ConsoleHelper.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

using namespace System;
using namespace Threading;

#define ESTADO_JOGO_MENU_PRINCIPAL 0
#define ESTADO_JOGO_GAMEPLAY 1
#define ESTADO_JOGO_GAMEOVER 2
#define ESTADO_JOGO_FINAL_CONGELADO 3
#define ESTADO_JOGO_FINAL_DESCONHECIDO 4
#define ESTADO_JOGO_FINAL_BADASS 5
#define ESTADO_JOGO_FINAL_ONE 6
int main()
{
	int escolha1, escolha2, escolha3, escolha4;
	setlocale(LC_ALL, "Portuguese");
	Console::SetWindowSize(80, 40);
	Console::SetBufferSize(80, 40);
	int estadoDoJogo;
	ConsoleKeyInfo tecla;
	char classe[20];
	char intro[880] = "Bem-vindo ao RPG World! Voc� n�o sabe o que � o RPG World? Bem, se voc� baixou esse jogo acho que deve ter lido alguma sinopse, n�o? O jogo n�o tem sinopse? Hmmm, bem, porque voc� baixou ent�o? S� porque o jogo tem o nome RPG seguido da palavra World voc� acha que o jogo vai ser um mundo aberto ou que vai ter cen�rios incr�veis e voc� vai ser o her�i da era medieval? Bem, que pena. Esse jogo vai ser baseado apenas em texto. Voc� n�o gosta de ler? Bem, ent�o v� jogar World of Warcraft, Skyrim ou Destiny. Creio que voc� se adaptar� melhor naqueles tipos de jogo onde voc� pula a parte chata de ler as miss�es e ver porque voc� est� catando plantas, matando monstros, e voc� apenas faz tudo aquilo para upar, conseguir itens melhores e conseguir dinheiro. Neste jogo voc� ir� criar sua pr�pria hist�ria, cada decis�o sua ter� efeitos diferentes no decorrer da hist�ria.\n\n\n";
	char medieval[800] = "Muito bem, ent�o vamos come�ar a hist�ria sobre um heroi na �poca medieval. H� muito tempo atr�s, um plebeu comum, estava voltando ao seu lar, ap�s ter assistido a um torneio realizado pelo rei, e ele esperava que um dia, ele teria as habilidades necess�rias para poder participar das justas e quem sabe, at� ganhar o pr�mio final que era 10.000 moedas de ouro para...";
	char decisao[800] = "1 - ajudar sua fam�lia pobre e conseguir um casa melhor para morar\n2- gastar tudo nos bord�is e beber at� desmaiar de cara no ch�o\n3- para doar para o orfanato, pois ele n�o queria ver as crian�as sofrendo\n4- viajar pelo mundo e conseguir muitos mais gl�ria e honra para sua fam�lia";
	char medieval2[800] = "Na metade do caminho, o sonhador plebeu ouviu uma algazarra vindo pr�xima ao seu vilarejo e viu uma grande nuvem de fuma�a e pessoas correndo desesperadamente para o castelo do rei, gritando por socorro. Desesperado, o plebeu";
	char decisao2[800] = "1- saiu correndo na dire��o da algazarra, para ver o que estava acontecendo, se debatendo no meio da multid�o\n2- saiu correndo junto com a popula��o desesperada, pois ele temia o pior\n3- saiu correndo entre a multid�o, para procurar seus familiares e amigos, e ver se todos estavam bem\n";
	char medieval3[800] = ", mas no meio da correria, ouviu pessoas gritando: �Drag�o! Drag�o! H� um drag�o atacando o vilarejo!�. No primeiro momento, ele n�o acreditou no que seria um drag�o, ele imaginou que deveria ser mais um dos truques dos magos atrapalhados, tentando fazer magias de fogo. \nAt� que ele viu uma sombra gigante voando por cima de sua cabe�a e pessoas apontando para uma criatura gigante nos c�us.Quando olhou pra cima, viu um...";
	char decisao3[800] = "1- ser enorme, cheio de escamas vermelho-sangue\n2- SPACESHIP!! SPACESHIP!! SPACESHIP!! SPACESHIP!!";
	char decisao4[500] = "1- sua casa o mais r�pido poss�vel, ver se sua fam�lia estava bem\n2- correu junto na multid�o para ver se conseguia um espa�o seguro no castelo\n";
	char decisao5[500] = "1- umas bolas que pareciam ser uns explosivos\n2- fogos de artificio, que poderiam ser usados para espantar o drag�o\n3- LXGIWYL, KJKSZPJ, UZUMYMW\n";
	char reinocongelado[1500] = "Dessa forma, ele pegou essas bolas estranhas, e saiu correndo para a torre dos magos que felizmente estava intacta e aproveitou que estava vazia e a porta estava aberta, subiu no topo o mais r�pido que pode, e come�ou a gritar e a derrubar as coisas da torre para chamar a aten��o do drag�o. O drag�o virou-se para ele de longe e apenas soltou uma baforada de fogo onde ele estava. Assustado, tentou desviar do fogo em sua dire��o, mas o fogo caiu perto demais dele, e queimou seu bra�o inteiro. Gritando de dor, o her�i caiu no ch�o da torre, sentindo o ch�o de pedra frio no seu rosto. Olhando para fora, conseguiu ver que o drag�o estava vindo em sua dire��o. Quando o drag�o chegou na torre, o her�i sabia que aquele era seu fim. O drag�o deu uma baforada no qual pegou o topo da torre inteira, queimando totalmente nosso her�i e tudo o que estava com ele. O que nosso her�i n�o sabia, � que aquela bola de fogo, era nada mais nada menos, a �ltima esfera feita pelo �ltimo mago de gelo que morreu h� trezentos anos atr�s, que quando era tocado por seu elemento inimigo, congelava tudo ao seu redor. Quando o fogo do drag�o tocou na esfera, a esfera explodiu, congelando todo o reino ao redor e transformando pessoas, animais e constru��es, em est�tuas congeladas que jamais iriam ser descongeladas novamente. Dessa forma, o reino ficou para sempre conhecido como o Reino Congelado.";
	char fogos[1600] = "Dessa forma, ele pegou os fogos de artif�cio, e saiu correndo para a torre dos magos que felizmente estava intacta e aproveitou que estava vazia e a porta estava aberta, subiu no topo o mais r�pido que pode, e come�ou a gritar e a derrubar as coisas da torre para chamar a aten��o do drag�o.O drag�o virou - se para ele de longe e apenas soltou uma baforada de fogo onde ele estava.Assustado, tentou desviar do fogo em sua dire��o, mas o fogo caiu perto demais dele, e queimou seu bra�o inteiro.Gritando de dor, o her�i caiu no ch�o da torre, sentindo o ch�o de pedra frio no seu rosto.Olhando para fora, conseguiu ver que o drag�o estava vindo em sua dire��o.Quando o drag�o chegou na torre, o her�i sabia que aquele era seu fim.O drag�o deu uma baforada no qual pegou o topo da torre inteira, queimando totalmente nosso her�i e tudo o que estava com ele.Felizmente, o fogo queimou os fogos de artif�cio, explodindo para tudo quanto � lado e um dos deles acertou a boca do drag�o.Assustado, o drag�o fugiu tentou fugir do reino, mas o fogo de artif�cio que acertou a boca do drag�o n�o tinha explodido, ent�o, segundos depois, ele explodiu, atordoando o drag�o que caiu com tudo no ch�o, esmagando diversas casas e pessoas que estavam fugindo.Com sorte, os cavaleiros do rei, aproveitaram a queda do drag�o e mataram ele antes que ele pudesse se recuperar do acontecido.Infelizmente, nosso her�i n�o ficou conhecido, pois o reino deu o acontecido como um acidente de fogos de artif�cio, que salvou o reino.E nosso her�i salvou a vida de todos os outros, sem nunca ficar conhecido.";
	char gta[800] = "Usando as manhas de armas do GTA San Andreas, nosso her�i, simplesmente pegou uma fucking BAZOOKA, mirou no drag�o que estava parado queimando pessoas no castelo e atirou... \n BOOOOM!!!! O drag�o explodiu em milhares de partes, espalhando sangue e peda�os do drag�o no castelo inteiro. Afinal, FODA-SE A L�GICA, BAZOOKAS S�O FODAS PRA CARALHO!!! \n Nosso her�i ficou conhecido como O MESTRE BOOM!!!";
	char alone[2500] = "Chegando no castelo, o port�o do castelo foi fechado pouco depois dele ter entrado. Quando o port�o fechou, o restante da popula��o que ficou para fora come�ou a gritar, chorar, crian�as estavam chorando, beb�s estavam assustado nos colos de suas m�es no meio de tanto barulho. E quem estava dentro do p�tio do castelo estava tentando entrar para dentro do castelo, mas al�m de a porta do castelo estar fechada, havia guardas protegendo e qualquer um que tentasse invadir o interior do castelo era expulso e alguns eram at� mortos por causa da ousadia. O desespero era geral, e o nosso plebeu percebeu que estava encrencado, pois ele estava preso num p�tio a ar aberto, e ele n�o podia sair e nem entrar no castelo. Ele tinha que fazer alguma coisa, agora ele percebeu que foi um idiota ter entrado no p�tio do castelo, nem ali eles estariam seguros, pois o drag�o de vez em quando baforava ondas de fogo contra o castelo, e muitos que estavam no p�tio eram atingidos. Ele estava num abatedouro. At� que ele teve uma ideia. Ele correu entre a multid�o tentando chegar no po�o d�agua do castelo. Chegando nela, ele viu se a corda que estava sendo usada aguentaria o peso dele. A corda estava forte o suficiente, ent�o rapidamente ele arrumou a corda para que desse uma altura suficiente numa ponta e a outra amarrou nele mesmo. Ap�s isso, ele se jogou no po�o. Quando atingiu o fundo sentiu a �gua gelada no corpo, e esperou que seu plano desse certo no final. Ele esperou algumas horas, alguns dias? Ele perdeu a no��o de tempo dentro do po�o at� perceber que o barulho de gritos e revolta tinha parado. Morrendo de frio e fome ele juntou for�as para escalar entre as pedras do po�o. Ao conseguir sair do po�o, ele sentou do lado do po�o e descansou na luz do sol, respirando fundo e desmaiou de sono ali mesmo. Ao acordar, e ao olhar ao redor, percebeu que o reino estava num sil�ncio que ele nunca viu. Ele estava morto? N�o, ao ele juntar as consci�ncias, ele percebeu que havia corpos queimados em todos os lugares, o teto do castelo fora totalmente distorcido e havia um buraco. O port�o do castelo estava aberto e queimado. Ao andar mais pela cidade atr�s de comida e recursos, ele n�o conseguiu achar nenhuma alma viva. Ele imaginou ent�o que ele foi o �nico a ter sobrevivido ao ataque. Ent�o, ele saiu da cidade com recursos suficientes para chegar ao reino vizinho. E assim, para sempre ele ficou conhecido como o �O �NICO SOBREVIVENTE�.";
	for (;;)
	{
		switch (estadoDoJogo)
		{
		case ESTADO_JOGO_MENU_PRINCIPAL:
			Console::BackgroundColor == ConsoleColor::Black;
			//Limpar a tela
			Console::Clear();
			Console::ForegroundColor == ConsoleColor::Blue;
			Console::SetCursorPosition(10, 10);
			Console::WriteLine("  _____  _____   _____  __          __        _     _ ");
			Console::SetCursorPosition(10, 11);
			Console::WriteLine(" |  __ \\|  __ \\ / ____| \\ \\        / /       | |   | |");
			Console::SetCursorPosition(10, 12);
			Console::WriteLine(" | |__) | |__) | |  __   \\ \\  /\\  / /__  _ __| | __| |");
			Console::SetCursorPosition(10, 13);
			Console::WriteLine(" |  _  /|  ___/| | |_ |   \\ \\/  \\/ / _ \\| '__| |/ _` |");
			Console::SetCursorPosition(10, 14);
			Console::WriteLine(" | | \\ \\| |    | |__| |    \\  /\\  / (_) | |  | | (_| |");
			Console::SetCursorPosition(10, 15);
			Console::WriteLine(" |_|  \\_\\_|     \\_____|     \\/  \\/ \\___/|_|  |_|\\__,_|");

			Console::SetCursorPosition(18, 18);
			Console::Write("Pressione <ENTER> para comecar...");
			Threading::Thread::Sleep(500);
			if (Console::KeyAvailable)
			{
				tecla = Console::ReadKey(true);
				if (tecla.Key == ConsoleKey::Enter)
				{
					estadoDoJogo = ESTADO_JOGO_GAMEPLAY;
				}
			}

			break;

		case ESTADO_JOGO_GAMEPLAY:
			Console::SetWindowSize(170, 40);
			Console::SetBufferSize(170, 40);
			Console::BackgroundColor = ConsoleColor::Black;
			Console::ForegroundColor = ConsoleColor::White;
			Console::Clear();
			Console::SetCursorPosition(0, 5);
			puts(intro);
			puts(medieval);
			puts(decisao);
			scanf_s("%d", &escolha1);
			if (escolha1 == 1)
			{
				char choose1[200] = "ajudar sua fam�lia pobre e conseguir um casa melhor para morar";
			}
			else if (escolha1 == 2)
			{
				char choose1[200] = "gastar tudo nos bord�is e beber at� desmaiar de cara no ch�o";
			}
			else if (escolha1 == 3)
			{
				char choose1[200] = "para doar para o orfanato, pois ele n�o queria ver as crian�as sofrendo";
			}
			else if (escolha1 == 4)
			{
				char choose1[200] = "viajar pelo mundo e conseguir muitos mais gl�ria e honra para sua fam�lia";
			}
			puts(medieval2);
			puts(decisao2);
			scanf_s("%d", &escolha2);
			if (escolha2 == 1)
			{
				char choose2[200] = "saiu correndo na dire��o da algazarra, para ver o que estava acontecendo, se debatendo no meio da multid�o";
			}
			else if (escolha2 == 2)
			{
				char choose2[200] = "saiu correndo junto com a popula��o desesperada, pois ele temia o pior";
			}
			else if (escolha2 == 3)
			{
				char choose2[200] = "saiu correndo entre a multid�o, para procurar seus familiares e amigos, e ver se todos estavam bem";
			}
			puts(medieval3);
			puts(decisao3);
			scanf_s("%d", &escolha3);
			if (escolha3 == 1)
			{
				system("cls");
				char choose3[60] = "ser enorme, cheio de escamas vermelho-sangue";
				char dragao[800] = "cuspindo fogo no p�tio do castelo do rei ,queimando guardas e pessoas nobres que estavam do lado de fora do castelo. Ele n�o acreditou no que seus olhos estavam vendo, drag�es estavam extintos a muitos anos, se tornando uma hist�ria para se contar para as crian�as. O ser enorme deu uma volta pelo castelo, irritado pelos arqueiros reais que estavam tentando, sem chance nenhuma, de derrotar o ser ou tentar espant�-lo. Mas o drag�o resolveu acabar com os seres insignificantes que estavam lhe irritando e soprou mais uma onda de fogo nos arqueiros reais, deixando-os totalmente queimados, espalhando cheiro de carne queimada e gritos de agonia para os que ainda estavam vivos. Desesperado, ele correu para...\n";
				puts(dragao);
				puts(decisao4);
				scanf_s("%d", &escolha4);
				if (escolha4 == 1)
				{
					char choose4[1400] = "Chegando na sua casa, depois de tanto esfor�o e desviar de tantas constru��es em fogo, chegou na sua casa, que por sorte, ainda estava intacta. Come�ou a gritar pela sua fam�lia, sua m�e, seu pai, seus irm�os, mas parecia que eles j� tinham sa�do de casa. Temendo pelo pior, saiu pela porta, e come�ou a olhar em todas as dire��es, gritando pelo nome dos seus familiares. Ao sair pela porta de sua casa e olhar ao redor, percebeu que a cidade estava um caos: pessoas fugindo para o castelo, cujo port�o fora fechado a poucos instantes, para proteger quem conseguiu entrar, pois dentro do castelo estavam os nobres e do lado de fora, ficaram os pobres plebeus. Muitas pessoas estavam tentando apagar o fogo das constru��es, sem muito sucesso, pois a cada volta que o drag�o fazia, mais constru��es pegavam fogo e mais pessoas eram queimadas vivas. Enquanto ele via tudo isso, ele fechou os olhos, respirou fundo e pensou: �O que irei fazer? A cidade n�o est� preparada para um ataque dessa magnitude, e ainda por cima, vindo dos c�us. � At� que ele se lembrou da loja dos explosivos dos feiticeiros que por sorte, estava intacta ainda. Talvez l� ele encontrasse algo que ajudasse a espantar o drag�o. Assim, ele correu direto para l�.\n\n Chegando l�, ele viu diversos tipos de ferramentas, bombas e uns trecos estranhos.Ele pegou...";
					puts(choose4);
					puts(decisao5);
					scanf_s("%d", &escolha4);
					{
						if (escolha4 == 1)
						{
							estadoDoJogo = ESTADO_JOGO_FINAL_CONGELADO;
							puts(reinocongelado);
						}
						else if (escolha4 == 2)
						{
							estadoDoJogo = ESTADO_JOGO_FINAL_DESCONHECIDO;
							puts(fogos);
						}
						else if (escolha4 == 3)
						{
							estadoDoJogo = ESTADO_JOGO_FINAL_BADASS;
							puts(gta);
						}
					}
				}
				else if (escolha4 == 2)
				{
					estadoDoJogo = ESTADO_JOGO_FINAL_ONE;
					puts(alone);
				}
			}
			else if (escolha3 == 2)
			{
				system("cls");
				char choose3[60] = "SPACESHIP!! SPACESHIP!! SPACESHIP!! SPACESHIP!!";
				char spaceship[1750] = "O QUE??? Mas o que o uma nave espacial faz no meio da minha hist�ria medieval? Isso n�o faz sentido... Naves espaciais n�o existiam na �poca medieval. O que voc� disse? A hist�ria � sua? Boa sorte com isso, provavelmente essa nave espacial deve ter um sido na corre��o da MINHA HIST�RIA, e o que voc� faz � apenas escolher as decis�es do seu heroizinho. J� que voc� estragou minha hist�ria sabe o que vai acontecer em seguida? Muito bem, hhhmhmmm.\n\n Ao ver o gigantesco drag�o com escamas vermelho - sangue sobrevoando o reino, o heroizinho gritou palavras sem sentido em outra l�ngua que ningu�m conhecia, provavelmente o heroizinho estava sob efeitos de drogas ou estava com o dem�nio no corpo, pois todos sabemos que SPACESHIP n�o � uma palavra do portugu�s e porque simples plebeus n�o tinham a m�nima no��o de outros idiomas.Correndo desesperadamente atr�s de sua magn�fica SPACESHIP, seja l� o que ele estava imaginando que o drag�o fosse, ele derrubou pessoas no caminho, empurrando todos para longe e come�ou a chamar o drag�o para que ele... pudesse entrar nele e viajar para o infinito e al�m ? Pois �, nosso heroizinho estava definitivamente louco.\n\n Chegando no castelo do rei, o heroizinho est�pido subiu a torre mais alta do castelo gritando pela sua SPACESHIP.Depois de subir tantos degraus, chegou no topo e come�ou a gritar cada mais deseperado : �SPACESHIP!!!SPACESHIP!!!SPACESHI!!!SPACESHIP!!!� at� que ele conseguiu chamar a aten��o do drag�o, onde o drag�o simplesmente deu uma grande baforada de fogo no topo da torre, acabando de vez com nosso heroizinho, que n�o virou her�i de coisa alguma.";
				Console::Clear();
				estadoDoJogo = ESTADO_JOGO_GAMEOVER;
				puts(spaceship);
				ConsoleHelper::ImprimirASCIIExtended(20, 20, "������� �������     �������  ������  ������  ������� ��    ��");
				ConsoleHelper::ImprimirASCIIExtended(20, 21, "��      ��          ��      ��    �� ��   �� ��      ��    ��");
				ConsoleHelper::ImprimirASCIIExtended(20, 22, "������� �����       �����   ��    �� ��   �� �����   ��    ��");
				ConsoleHelper::ImprimirASCIIExtended(20, 23, "     �� ��          ��      ��    �� ��   �� ��      ��    ��");
				ConsoleHelper::ImprimirASCIIExtended(20, 24, "������� �������     ��       ������  ������  �������  ������ ");
			}
			break;
		}

	}
	return 0;
	system("pause");
}