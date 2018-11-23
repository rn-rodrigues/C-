#include <iostream>

using namespace std;

#define MAX 1000

class Pilha {
	public:
    int elementos[MAX] ;
    int N;          //NUMERO DE ELEMENTOS ATUAL DA PILHA
    void constroi() {
    	N=0;
    }
    void destroi() {
            //REPRESENTAÇÃO VAZIA
    }
        
    int topo() {
    	return elementos[N-1];
    }    
    void push(int valor) {        //EMPILHA
    	if (elementos[N] == MAX) {
    		printf("ERROR - Pilha cheia");
		}
        else {
		    elementos[N] = valor;
            N++;
        }
	}
	int pop() {             //DESEMPILHA
	    N = N-1;
        return elementos[N];
    }
    void DEPTH() {     //ADICIONA NÚMERO DE ELEMENTOS DE P1 NO TOPO DE P1
    	push(N);  
    }
    void DROP() {     //ELIMINA O ELEMENTO DO TOPO DE P1
    	pop();
    }
    void DUP() {      //ADICIONA NO TOPO UMA CÓPIA DO TOPO EXISTENTE
    	int val = topo();
        push(val);
    }
    void DUPFROMALTSTACK(Pilha p2) {  //CLONA TOPO DE P2 E COLOCA EM P1
    	int val = p2.topo();
        push(val);
    }
	void NIP(Pilha p2) {	//Remove o segundo elemento no topo de P1
		p2.push(pop());
		int val = pop();
		push(p2.pop());
	}
	void SWAP() {	//Troca os dois elementos no topo de P1
		int x = pop();
		int y = pop();
		push(x);
		push(y);
	}
	void ROT() {	//Os elementos no topo de P1 são rotacionados (exemplo: A B C (C é o topo) -> B C A
		int c = pop();
		int b = pop();
		int a = pop();
		push(b);
		push(c);
		push(a);	
	}
	void TUCK() {	//O elemento no topo de P1 é copiado e inserido na segunda posição após o topo de P1
		int aux = topo();
		int aux2 = pop();
		push(aux);
		push(aux2);
	}
	void OVER() {	//Copia o segundo elemento do topo de P1 para o topo de P1
		int aux = pop();
		int aux2 = topo();
		push(aux);
		push(aux2);
	}		
	// FUNÇÕES AVANÇADAS
	void ROLL(Pilha p2, int n) {	//O item da posição n após o topo é movido para o topo de P1
		int aux;
		while (N > n) {
			p2.push(pop());		
		}
		aux = pop();
		while (p2.N > 3) {
			push(p2.pop());		
		}
		push(aux);
	}
	void PICK(Pilha p2, int n) {	//O item da posição n após o topo é copiado para o topo de P1
		int aux;
		while (N > n) {
			p2.push(pop());		
		}
		aux = topo();
		while (p2.N > 3) {
			push(p2.pop());		
		}
		push(aux);
	}
	void XSWAP(Pilha p2, int n) {	//O elemento na posição n da pilha P1 é trocado com o topo de P1 (exemplo: XSWAP(n=2) é equivalente a SWAP)
		int aux = pop(); // topo de p1
		while (N > n) {
			p2.push(pop());		
		}
		int aux2 = pop(); // posição n
		push(aux);
		while (p2.N > 3) {
			push(p2.pop());		
		}
		push(aux2);
	}
	void XTUCK(Pilha p2, int n) {	//O item no topo de P1 é colocado na posição n de P1 (exemplo: XTUCK(n=2) é equivalente a TUCK)		
		int aux = topo(); // topo de p1
		while (N >= n) {
			p2.push(pop());		
		}
		push(aux);	// posição n		
		while (p2.N > 3) {
			push(p2.pop());		
		}
	}
};

int main () {
	Pilha p1, p2;
	int n;	//Posição escolhida à ser manipulada
    p1.constroi();
    p2.constroi();
    
	p1.push(2);
    p1.push(3);
    p1.push(4);	//-> TOPO      

    p2.push(5);
    p2.push(6);
    p2.push(7);	//-> TOPO

	printf("Posição à ser manipulada: ");
	scanf("%d", &n);
	p1.XTUCK(p2, n);
    printf("\nPilha 1:\n");
    while (p1.N > 0) {
	    printf("%d\n", p1.pop());
    }
	printf("\n");
    return 0;
}

