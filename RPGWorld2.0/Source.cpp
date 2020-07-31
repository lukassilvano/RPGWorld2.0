//OBSERVAÇÃO: TEVE MUITA COISA QUE PRECISEI RETIRAR DEVIDO AO TEMPO COMO POR EXEMPLO 2 HISTÓRIAS DIFERENTES, QUE IA SE
//PASSAR NO PRESENTE E NO FUTURO, ALÉM DE MAIS ESCOLHAS NA ÉPOCA MEDIEVAL, MAS DEVIDO AO TEMPO, PRECISEI REDUZIR AO MÁXIMO
//A HISTÓRIA DO JOGO, ENTÃO ESPERO QUE O QUE TENHA SEJA SUFICIENTE.

//Eu tentei meio que fazer um livro de RPG, onde as suas escolhas te levam para caminhos diferente, só que numa versão digital.
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
	char intro[880] = "Bem-vindo ao RPG World! Você não sabe o que é o RPG World? Bem, se você baixou esse jogo acho que deve ter lido alguma sinopse, não? O jogo não tem sinopse? Hmmm, bem, porque você baixou então? Só porque o jogo tem o nome RPG seguido da palavra World você acha que o jogo vai ser um mundo aberto ou que vai ter cenários incríveis e você vai ser o herói da era medieval? Bem, que pena. Esse jogo vai ser baseado apenas em texto. Você não gosta de ler? Bem, então vá jogar World of Warcraft, Skyrim ou Destiny. Creio que você se adaptará melhor naqueles tipos de jogo onde você pula a parte chata de ler as missões e ver porque você está catando plantas, matando monstros, e você apenas faz tudo aquilo para upar, conseguir itens melhores e conseguir dinheiro. Neste jogo você irá criar sua própria história, cada decisão sua terá efeitos diferentes no decorrer da história.\n\n\n";
	char medieval[800] = "Muito bem, então vamos começar a história sobre um heroi na época medieval. Há muito tempo atrás, um plebeu comum, estava voltando ao seu lar, após ter assistido a um torneio realizado pelo rei, e ele esperava que um dia, ele teria as habilidades necessárias para poder participar das justas e quem sabe, até ganhar o prêmio final que era 10.000 moedas de ouro para...";
	char decisao[800] = "1 - ajudar sua família pobre e conseguir um casa melhor para morar\n2- gastar tudo nos bordéis e beber até desmaiar de cara no chão\n3- para doar para o orfanato, pois ele não queria ver as crianças sofrendo\n4- viajar pelo mundo e conseguir muitos mais glória e honra para sua família";
	char medieval2[800] = "Na metade do caminho, o sonhador plebeu ouviu uma algazarra vindo próxima ao seu vilarejo e viu uma grande nuvem de fumaça e pessoas correndo desesperadamente para o castelo do rei, gritando por socorro. Desesperado, o plebeu";
	char decisao2[800] = "1- saiu correndo na direção da algazarra, para ver o que estava acontecendo, se debatendo no meio da multidão\n2- saiu correndo junto com a população desesperada, pois ele temia o pior\n3- saiu correndo entre a multidão, para procurar seus familiares e amigos, e ver se todos estavam bem\n";
	char medieval3[800] = ", mas no meio da correria, ouviu pessoas gritando: “Dragão! Dragão! Há um dragão atacando o vilarejo!”. No primeiro momento, ele não acreditou no que seria um dragão, ele imaginou que deveria ser mais um dos truques dos magos atrapalhados, tentando fazer magias de fogo. \nAté que ele viu uma sombra gigante voando por cima de sua cabeça e pessoas apontando para uma criatura gigante nos céus.Quando olhou pra cima, viu um...";
	char decisao3[800] = "1- ser enorme, cheio de escamas vermelho-sangue\n2- SPACESHIP!! SPACESHIP!! SPACESHIP!! SPACESHIP!!";
	char decisao4[500] = "1- sua casa o mais rápido possível, ver se sua família estava bem\n2- correu junto na multidão para ver se conseguia um espaço seguro no castelo\n";
	char decisao5[500] = "1- umas bolas que pareciam ser uns explosivos\n2- fogos de artificio, que poderiam ser usados para espantar o dragão\n3- LXGIWYL, KJKSZPJ, UZUMYMW\n";
	char reinocongelado[1500] = "Dessa forma, ele pegou essas bolas estranhas, e saiu correndo para a torre dos magos que felizmente estava intacta e aproveitou que estava vazia e a porta estava aberta, subiu no topo o mais rápido que pode, e começou a gritar e a derrubar as coisas da torre para chamar a atenção do dragão. O dragão virou-se para ele de longe e apenas soltou uma baforada de fogo onde ele estava. Assustado, tentou desviar do fogo em sua direção, mas o fogo caiu perto demais dele, e queimou seu braço inteiro. Gritando de dor, o herói caiu no chão da torre, sentindo o chão de pedra frio no seu rosto. Olhando para fora, conseguiu ver que o dragão estava vindo em sua direção. Quando o dragão chegou na torre, o herói sabia que aquele era seu fim. O dragão deu uma baforada no qual pegou o topo da torre inteira, queimando totalmente nosso herói e tudo o que estava com ele. O que nosso herói não sabia, é que aquela bola de fogo, era nada mais nada menos, a última esfera feita pelo último mago de gelo que morreu há trezentos anos atrás, que quando era tocado por seu elemento inimigo, congelava tudo ao seu redor. Quando o fogo do dragão tocou na esfera, a esfera explodiu, congelando todo o reino ao redor e transformando pessoas, animais e construções, em estátuas congeladas que jamais iriam ser descongeladas novamente. Dessa forma, o reino ficou para sempre conhecido como o Reino Congelado.";
	char fogos[1600] = "Dessa forma, ele pegou os fogos de artifício, e saiu correndo para a torre dos magos que felizmente estava intacta e aproveitou que estava vazia e a porta estava aberta, subiu no topo o mais rápido que pode, e começou a gritar e a derrubar as coisas da torre para chamar a atenção do dragão.O dragão virou - se para ele de longe e apenas soltou uma baforada de fogo onde ele estava.Assustado, tentou desviar do fogo em sua direção, mas o fogo caiu perto demais dele, e queimou seu braço inteiro.Gritando de dor, o herói caiu no chão da torre, sentindo o chão de pedra frio no seu rosto.Olhando para fora, conseguiu ver que o dragão estava vindo em sua direção.Quando o dragão chegou na torre, o herói sabia que aquele era seu fim.O dragão deu uma baforada no qual pegou o topo da torre inteira, queimando totalmente nosso herói e tudo o que estava com ele.Felizmente, o fogo queimou os fogos de artifício, explodindo para tudo quanto é lado e um dos deles acertou a boca do dragão.Assustado, o dragão fugiu tentou fugir do reino, mas o fogo de artifício que acertou a boca do dragão não tinha explodido, então, segundos depois, ele explodiu, atordoando o dragão que caiu com tudo no chão, esmagando diversas casas e pessoas que estavam fugindo.Com sorte, os cavaleiros do rei, aproveitaram a queda do dragão e mataram ele antes que ele pudesse se recuperar do acontecido.Infelizmente, nosso herói não ficou conhecido, pois o reino deu o acontecido como um acidente de fogos de artifício, que salvou o reino.E nosso herói salvou a vida de todos os outros, sem nunca ficar conhecido.";
	char gta[800] = "Usando as manhas de armas do GTA San Andreas, nosso herói, simplesmente pegou uma fucking BAZOOKA, mirou no dragão que estava parado queimando pessoas no castelo e atirou... \n BOOOOM!!!! O dragão explodiu em milhares de partes, espalhando sangue e pedaços do dragão no castelo inteiro. Afinal, FODA-SE A LÓGICA, BAZOOKAS SÃO FODAS PRA CARALHO!!! \n Nosso herói ficou conhecido como O MESTRE BOOM!!!";
	char alone[2500] = "Chegando no castelo, o portão do castelo foi fechado pouco depois dele ter entrado. Quando o portão fechou, o restante da população que ficou para fora começou a gritar, chorar, crianças estavam chorando, bebês estavam assustado nos colos de suas mães no meio de tanto barulho. E quem estava dentro do pátio do castelo estava tentando entrar para dentro do castelo, mas além de a porta do castelo estar fechada, havia guardas protegendo e qualquer um que tentasse invadir o interior do castelo era expulso e alguns eram até mortos por causa da ousadia. O desespero era geral, e o nosso plebeu percebeu que estava encrencado, pois ele estava preso num pátio a ar aberto, e ele não podia sair e nem entrar no castelo. Ele tinha que fazer alguma coisa, agora ele percebeu que foi um idiota ter entrado no pátio do castelo, nem ali eles estariam seguros, pois o dragão de vez em quando baforava ondas de fogo contra o castelo, e muitos que estavam no pátio eram atingidos. Ele estava num abatedouro. Até que ele teve uma ideia. Ele correu entre a multidão tentando chegar no poço d’agua do castelo. Chegando nela, ele viu se a corda que estava sendo usada aguentaria o peso dele. A corda estava forte o suficiente, então rapidamente ele arrumou a corda para que desse uma altura suficiente numa ponta e a outra amarrou nele mesmo. Após isso, ele se jogou no poço. Quando atingiu o fundo sentiu a água gelada no corpo, e esperou que seu plano desse certo no final. Ele esperou algumas horas, alguns dias? Ele perdeu a noção de tempo dentro do poço até perceber que o barulho de gritos e revolta tinha parado. Morrendo de frio e fome ele juntou forças para escalar entre as pedras do poço. Ao conseguir sair do poço, ele sentou do lado do poço e descansou na luz do sol, respirando fundo e desmaiou de sono ali mesmo. Ao acordar, e ao olhar ao redor, percebeu que o reino estava num silêncio que ele nunca viu. Ele estava morto? Não, ao ele juntar as consciências, ele percebeu que havia corpos queimados em todos os lugares, o teto do castelo fora totalmente distorcido e havia um buraco. O portão do castelo estava aberto e queimado. Ao andar mais pela cidade atrás de comida e recursos, ele não conseguiu achar nenhuma alma viva. Ele imaginou então que ele foi o único a ter sobrevivido ao ataque. Então, ele saiu da cidade com recursos suficientes para chegar ao reino vizinho. E assim, para sempre ele ficou conhecido como o ‘O ÚNICO SOBREVIVENTE’.";
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
				char choose1[200] = "ajudar sua família pobre e conseguir um casa melhor para morar";
			}
			else if (escolha1 == 2)
			{
				char choose1[200] = "gastar tudo nos bordéis e beber até desmaiar de cara no chão";
			}
			else if (escolha1 == 3)
			{
				char choose1[200] = "para doar para o orfanato, pois ele não queria ver as crianças sofrendo";
			}
			else if (escolha1 == 4)
			{
				char choose1[200] = "viajar pelo mundo e conseguir muitos mais glória e honra para sua família";
			}
			puts(medieval2);
			puts(decisao2);
			scanf_s("%d", &escolha2);
			if (escolha2 == 1)
			{
				char choose2[200] = "saiu correndo na direção da algazarra, para ver o que estava acontecendo, se debatendo no meio da multidão";
			}
			else if (escolha2 == 2)
			{
				char choose2[200] = "saiu correndo junto com a população desesperada, pois ele temia o pior";
			}
			else if (escolha2 == 3)
			{
				char choose2[200] = "saiu correndo entre a multidão, para procurar seus familiares e amigos, e ver se todos estavam bem";
			}
			puts(medieval3);
			puts(decisao3);
			scanf_s("%d", &escolha3);
			if (escolha3 == 1)
			{
				system("cls");
				char choose3[60] = "ser enorme, cheio de escamas vermelho-sangue";
				char dragao[800] = "cuspindo fogo no pátio do castelo do rei ,queimando guardas e pessoas nobres que estavam do lado de fora do castelo. Ele não acreditou no que seus olhos estavam vendo, dragões estavam extintos a muitos anos, se tornando uma história para se contar para as crianças. O ser enorme deu uma volta pelo castelo, irritado pelos arqueiros reais que estavam tentando, sem chance nenhuma, de derrotar o ser ou tentar espantá-lo. Mas o dragão resolveu acabar com os seres insignificantes que estavam lhe irritando e soprou mais uma onda de fogo nos arqueiros reais, deixando-os totalmente queimados, espalhando cheiro de carne queimada e gritos de agonia para os que ainda estavam vivos. Desesperado, ele correu para...\n";
				puts(dragao);
				puts(decisao4);
				scanf_s("%d", &escolha4);
				if (escolha4 == 1)
				{
					char choose4[1400] = "Chegando na sua casa, depois de tanto esforço e desviar de tantas construções em fogo, chegou na sua casa, que por sorte, ainda estava intacta. Começou a gritar pela sua família, sua mãe, seu pai, seus irmãos, mas parecia que eles já tinham saído de casa. Temendo pelo pior, saiu pela porta, e começou a olhar em todas as direções, gritando pelo nome dos seus familiares. Ao sair pela porta de sua casa e olhar ao redor, percebeu que a cidade estava um caos: pessoas fugindo para o castelo, cujo portão fora fechado a poucos instantes, para proteger quem conseguiu entrar, pois dentro do castelo estavam os nobres e do lado de fora, ficaram os pobres plebeus. Muitas pessoas estavam tentando apagar o fogo das construções, sem muito sucesso, pois a cada volta que o dragão fazia, mais construções pegavam fogo e mais pessoas eram queimadas vivas. Enquanto ele via tudo isso, ele fechou os olhos, respirou fundo e pensou: ‘O que irei fazer? A cidade não está preparada para um ataque dessa magnitude, e ainda por cima, vindo dos céus. ’ Até que ele se lembrou da loja dos explosivos dos feiticeiros que por sorte, estava intacta ainda. Talvez lá ele encontrasse algo que ajudasse a espantar o dragão. Assim, ele correu direto para lá.\n\n Chegando lá, ele viu diversos tipos de ferramentas, bombas e uns trecos estranhos.Ele pegou...";
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
				char spaceship[1750] = "O QUE??? Mas o que o uma nave espacial faz no meio da minha história medieval? Isso não faz sentido... Naves espaciais não existiam na época medieval. O que você disse? A história é sua? Boa sorte com isso, provavelmente essa nave espacial deve ter um sido na correção da MINHA HISTÓRIA, e o que você faz é apenas escolher as decisões do seu heroizinho. Já que você estragou minha história sabe o que vai acontecer em seguida? Muito bem, hhhmhmmm.\n\n Ao ver o gigantesco dragão com escamas vermelho - sangue sobrevoando o reino, o heroizinho gritou palavras sem sentido em outra língua que ninguém conhecia, provavelmente o heroizinho estava sob efeitos de drogas ou estava com o demônio no corpo, pois todos sabemos que SPACESHIP não é uma palavra do português e porque simples plebeus não tinham a mínima noção de outros idiomas.Correndo desesperadamente atrás de sua magnífica SPACESHIP, seja lá o que ele estava imaginando que o dragão fosse, ele derrubou pessoas no caminho, empurrando todos para longe e começou a chamar o dragão para que ele... pudesse entrar nele e viajar para o infinito e além ? Pois é, nosso heroizinho estava definitivamente louco.\n\n Chegando no castelo do rei, o heroizinho estúpido subiu a torre mais alta do castelo gritando pela sua SPACESHIP.Depois de subir tantos degraus, chegou no topo e começou a gritar cada mais deseperado : “SPACESHIP!!!SPACESHIP!!!SPACESHI!!!SPACESHIP!!!” até que ele conseguiu chamar a atenção do dragão, onde o dragão simplesmente deu uma grande baforada de fogo no topo da torre, acabando de vez com nosso heroizinho, que não virou herói de coisa alguma.";
				Console::Clear();
				estadoDoJogo = ESTADO_JOGO_GAMEOVER;
				puts(spaceship);
				ConsoleHelper::ImprimirASCIIExtended(20, 20, "ÛÛÛÛÛÛÛ ÛÛÛÛÛÛÛ     ÛÛÛÛÛÛÛ  ÛÛÛÛÛÛ  ÛÛÛÛÛÛ  ÛÛÛÛÛÛÛ ÛÛ    ÛÛ");
				ConsoleHelper::ImprimirASCIIExtended(20, 21, "ÛÛ      ÛÛ          ÛÛ      ÛÛ    ÛÛ ÛÛ   ÛÛ ÛÛ      ÛÛ    ÛÛ");
				ConsoleHelper::ImprimirASCIIExtended(20, 22, "ÛÛÛÛÛÛÛ ÛÛÛÛÛ       ÛÛÛÛÛ   ÛÛ    ÛÛ ÛÛ   ÛÛ ÛÛÛÛÛ   ÛÛ    ÛÛ");
				ConsoleHelper::ImprimirASCIIExtended(20, 23, "     ÛÛ ÛÛ          ÛÛ      ÛÛ    ÛÛ ÛÛ   ÛÛ ÛÛ      ÛÛ    ÛÛ");
				ConsoleHelper::ImprimirASCIIExtended(20, 24, "ÛÛÛÛÛÛÛ ÛÛÛÛÛÛÛ     ÛÛ       ÛÛÛÛÛÛ  ÛÛÛÛÛÛ  ÛÛÛÛÛÛÛ  ÛÛÛÛÛÛ ");
			}
			break;
		}

	}
	return 0;
	system("pause");
}