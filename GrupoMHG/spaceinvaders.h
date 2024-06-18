/*
    Grupo MHG
    Integrantes:
        - Mateus Carmo de Oliveira (11911BCC026)
        - Hendrik Abdalla Hermann (11911BCC034)
        - Gabriel Joshua Calixto Naves dos Santos (11911BCC052)
*/

#define ALIENX 5
#define ALIENY 7
#define ALIENTIMERDEFAULT 80
#define COOLDOWN 60
#define TAMANHO 0.042
#define NUMTIROSALIADOS 2
#define NUMTIROSINIMIGOS 10
#define VELOCIDADETIRO 0.015
#define BORDAX 0.5
#define BORDAY 0.8
#define OFFSET 0.058

typedef struct Point Point;
typedef struct TNave Nave;
typedef struct TAlien Alien;
typedef struct Tiro Tiro;

void carregarTexturas();

//============ Nave =======================================================================

Nave* nave_create(float _x, float _y);
void nave_destroy(Nave *_nave);
int get_nave_morteTimer(Nave *_nave);
void desenhaNave(Nave *_nave);
void mover_nave(Nave *_nave, bool setaDireita, bool setaEsquerda, float vel_movimento);
void nave_atira(Nave *_nave, Tiro *_tiro);
void nave_set_estado(Nave *_nave, bool estado);

void get_pos_nave(Nave *_nave);
void set_pos_nave(Nave *_nave, float posX, float posY);

//============ Alien =======================================================================

Alien* alien_create(float _x, float _y, int alienTipo);
void alien_destroy(Alien *_alien);
bool alien_vivo(Alien *_alien);
void alien_set_estado(Alien *_alien, bool estado);
void desenhaAlien(Alien *_alien);
void mover_alien(Alien *_alien, int direcao, float velocidade);
void mover_alien_especial(Alien *_alien);
float get_pos_alienX(Alien *_alien);
float get_pos_alienY(Alien *_alien);
void set_pos_alien(Alien *_alien, float _x, float _y);
void descer_alien(Alien *_alien);

//============ Tiro =======================================================================

Tiro* instanciar_tiro(float posX, float posY);
void tiro_destroy(Tiro *tiro);
bool tiro_ativo(Tiro *_tiro);
void guardar_tiro(Tiro *_tiro);
void desenhaTiro(Tiro *_tiro);
void mover_tiro(Tiro *_tiro);
void detectar_colisao_alien(Alien *_alien, Tiro *_tiro, int *score);

//============ Interfaco do Usuário =======================================================================

void desenhaScore(int score, int numDigitos, bool segredo);
void desenhaOverlay();
void desenhaTextos(float posX, float posY, float tam, int idTexto);
