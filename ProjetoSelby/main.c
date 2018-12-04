//DECLARA ALLEGRO
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_acodec.h>
//DECLARA C
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>


// CONSTANTES DO DISPLAY
const int LARGURA_TELA = 1280;
const int ALTURA_TELA = 720;


//PARTES DO JOGO
#define P_APRESENTACAO 0
#define P_MENU 1
#define P_BOASVINDAS 2
#define P_TRANSICAO_NIVEL_1 3
#define P_NIVEL_1 4
#define P_TRANSICAO_NIVEL_2 5
#define P_NIVEL_2 6
#define P_FINAL 9


//VARIAVEIS ALLEGRO
ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_FONT *titulo = NULL;
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_BITMAP *x = NULL;
ALLEGRO_COLOR cor_menu;
ALLEGRO_COLOR cor_titulo;


//VARIAVEIS DE CONTROLE
int controle = 0;


int inicializar(){
	printf(">>> Iniciando o jogo...\n");
	int sucesso = 0;

	printf(">>> Iniciando Funcoes\n");
	if(!al_init()){
		fprintf(stderr, "al_init\n");
	}else if(!(janela = al_create_display(LARGURA_TELA,ALTURA_TELA))){
		fprintf(stderr, "al_create_display\n");
	}else if(!al_init_primitives_addon()){
		fprintf(stderr, "al_init_primitives_addon\n");
	}else if (!al_init_font_addon()) {
		fprintf(stderr, "inicializa_font\n");
	}else if(!(titulo = al_load_font("res/font/comic.ttf", 48, 0))){
		fprintf(stderr, "erro na fonte do titulo\n");
	}else if(!al_install_keyboard()){
		fprintf(stderr, "al_install_keyboard\n");
	}else if(!al_install_joystick()){
		fprintf(stderr, "al_install_joystick\n");
	}else if(!al_install_mouse()){
		fprintf(stderr, "al_install_mouse\n");
	}else if (!(fila_eventos = al_create_event_queue())) {
		fprintf(stderr, "al_create_event_queue\n");
	}else if(!al_install_mouse()){
		fprintf(stderr, "al_install_mouse\n");
	}else if(!al_init_image_addon()){
		fprintf(stderr, "al_init_image_addon\n");
	}else {
		sucesso = 1;

        al_set_window_title(janela, "*SELBY SPACE*");// DEFINE NOME DA JANELA
        al_register_event_source(fila_eventos, al_get_display_event_source(janela)); /*Registra os eventos que ocorrem dentro da janela*/
        al_register_event_source(fila_eventos, al_get_keyboard_event_source()); /*Registra os eventos do teclado*/

        printf(">>> Funcoes Iniciadas\n");
    }
}


void troca_tela(ALLEGRO_BITMAP *img1, ALLEGRO_BITMAP *img2){
	al_destroy_bitmap(img1);
	al_flip_display();
	al_draw_bitmap(img2, 0, 0, 0);
	al_flip_display();
}


void destroy(){
	if(janela)	al_destroy_display(janela);
	if(titulo) al_destroy_font(titulo);
	if(fonte) al_destroy_font(fonte);
	if(titulo) al_destroy_font(titulo);
	if(fila_eventos) al_destroy_event_queue(fila_eventos);
	al_uninstall_mouse();
	al_uninstall_keyboard();
	al_uninstall_joystick();
	al_uninstall_audio();
	al_shutdown_image_addon();
	al_shutdown_ttf_addon();
	al_shutdown_font_addon();
	al_shutdown_primitives_addon();
}


void apresentacao(){
	printf(">>> Declara vetor da apresentacao");
	ALLEGRO_BITMAP *apresentacao[10] = {NULL, NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL, NULL};//VARIAVEL DA APRESENTAÇÂO

	printf(">>> Atribui valor ao vetor apresentação\n");
	apresentacao[0] = al_load_bitmap("res/img/01_APRESENTACAO/a1.bmp");
	apresentacao[1] = al_load_bitmap("res/img/01_APRESENTACAO/a2.bmp");
	apresentacao[2] = al_load_bitmap("res/img/01_APRESENTACAO/a3.bmp");
	apresentacao[3] = al_load_bitmap("res/img/01_APRESENTACAO/a4.bmp");
	apresentacao[4] = al_load_bitmap("res/img/01_APRESENTACAO/a5.bmp");
	apresentacao[5] = al_load_bitmap("res/img/01_APRESENTACAO/a6.bmp");
	apresentacao[6] = al_load_bitmap("res/img/01_APRESENTACAO/a7.bmp");
	apresentacao[7] = al_load_bitmap("res/img/01_APRESENTACAO/a8.bmp");
	apresentacao[8] = al_load_bitmap("res/img/01_APRESENTACAO/a9.bmp");
	apresentacao[9] = al_load_bitmap("res/img/01_APRESENTACAO/a10.bmp");
	printf(">>> Valores atribuidos\n");

	printf(">>> Inicializa apresenação\n");
	al_draw_bitmap(apresentacao[0], 0, 0, 0);
	al_rest(1.0);
	al_flip_display();
	troca_tela(apresentacao[0], apresentacao[1]);
	al_rest(2.5);
	troca_tela(apresentacao[1], apresentacao[2]);
	al_rest(0.1);
	troca_tela(apresentacao[2], apresentacao[3]);
	al_rest(0.1);
	troca_tela(apresentacao[3], apresentacao[4]);
	al_rest(0.1);
	troca_tela(apresentacao[4], apresentacao[5]);
	al_rest(0.1);
	troca_tela(apresentacao[5], apresentacao[6]);
	al_rest(0.1);
	troca_tela(apresentacao[6], apresentacao[7]);
	al_rest(0.1);
	troca_tela(apresentacao[7], apresentacao[8]);
	al_rest(0.1);
	troca_tela(apresentacao[8], apresentacao[9]);
	al_destroy_bitmap(apresentacao[9]);
	al_flip_display();

	printf(">>> Finaliza apresentação\n");


	controle++;
}

void desenha_tela_inicio(){
	printf(">>> Inicia função desenha tela inicio\n");
	ALLEGRO_BITMAP *tela_inicio = NULL;

	tela_inicio = al_load_bitmap("res/img/02_MENU/menu.bmp");
	al_draw_bitmap(tela_inicio, 0, 0, 0);
	al_flip_display();
	printf(">>> Tela de inicio desenhada\n");
}


int pega_tecla(){
	ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
	ALLEGRO_FONT *fonte = NULL;

	if (!al_install_keyboard()){
		printf("Falha ao inicializar o teclado");
	}


	fila_eventos = al_create_event_queue();
	if (!fila_eventos){
		printf("Falha ao criar fila de eventos");
		al_destroy_display(janela);
	}

	al_register_event_source(fila_eventos, al_get_keyboard_event_source());

	int sair = 0;
	int tecla = 0;

	while (!sair){
		while(!al_is_event_queue_empty(fila_eventos)){
			ALLEGRO_EVENT evento;
			al_wait_for_event(fila_eventos, &evento);

			if (evento.type == ALLEGRO_EVENT_KEY_DOWN){
				switch(evento.keyboard.keycode){
					case ALLEGRO_KEY_SPACE:
					tecla = 1;
					break;
					case ALLEGRO_KEY_ESCAPE:
					sair = 1;
					break;
				}
			}
			else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
				sair = 1;
			}
		}

		if (tecla){
			if (tecla == 1){
				return 1;
			} else{
				return 0;
			}
		}
		tecla = 0;
	}

	al_destroy_event_queue(fila_eventos);

}


void menu(){
	printf(">>> Inicio função menu\n");
	desenha_tela_inicio();
	{
		if(pega_tecla() != 1){
			controle++;

		}

		controle++;


	}
}




void boas_vindas(){
	ALLEGRO_BITMAP *boasvindas[4] = {NULL,NULL,NULL};

	boasvindas[0] = al_load_bitmap("res/img/03_BOASVINDAS/b1.bmp");
	boasvindas[1] = al_load_bitmap("res/img/03_BOASVINDAS/b2.bmp");
	boasvindas[2] = al_load_bitmap("res/img/03_BOASVINDAS/b3.bmp");
	boasvindas[3] = al_load_bitmap("res/img/03_BOASVINDAS/b4.bmp");

	al_flip_display();
	al_draw_bitmap(boasvindas[0], 0, 0, 0);
	al_rest(6.0);

	al_flip_display();
	al_draw_bitmap(boasvindas[1], 0, 0, 0);
	al_destroy_bitmap(boasvindas[0]);
	al_rest(6.0);

	al_flip_display();
	al_draw_bitmap(boasvindas[2], 0, 0, 0);
	al_destroy_bitmap(boasvindas[1]);
	al_rest(3.0);

	al_flip_display();
	al_draw_bitmap(boasvindas[3], 0, 0, 0);
	al_destroy_bitmap(boasvindas[2]);
	al_rest(3.0);


	al_flip_display();
	al_draw_bitmap(boasvindas[4], 0, 0, 0);
	al_flip_display();

	al_rest(7.0);



	controle++;
}







int main(){
	if(!inicializar()){
		return -1;
	}


	while(controle != P_FINAL){
		if(controle == P_APRESENTACAO){
			apresentacao();
		} else if(controle == P_MENU){
			menu();
		} else if(controle == P_BOASVINDAS){
			boas_vindas();
		} else if(controle == P_TRANSICAO_NIVEL_1){
			printf("OKOK\n");
			break;
		}
	}



	destroy();
	return 0;
}

