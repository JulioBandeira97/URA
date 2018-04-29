#include "ControleMovimento.h" 

ControleMovimento::ControleMovimento(){
  incEsq = 100; 
  incDir = 100; 
 
}


void ControleMovimento::setup(int pinEMotor, int pinDMotor, int pinESensor, int pinDSensor){
  contaGE.setup(pinESensor,200);
  contaGD.setup(pinDSensor,600);
  mEsquerdo.attach(pinEMotor); 
  mDireito.attach(pinDMotor); 
  pararMDireito = 1470; 
  pararMEsquerdo = 1620;  
 
} 

void ControleMovimento::setup(int pinEMotor, int pinDMotor, int pinESensor, int pinDSensor, int pwmEsq, int pwmDir){
  contaGE.setup(pinESensor,200);
  contaGD.setup(pinDSensor,600);
  mEsquerdo.attach(pinEMotor); 
  mDireito.attach(pinDMotor); 
  pararMDireito = pwmDir; 
  pararMEsquerdo = pwmEsq; 



  Serial.begin(9600); 
} 

void ControleMovimento::moveMotores(int pulsoEsq, int pulsoDir) {
    mEsquerdo.writeMicroseconds(pararMEsquerdo - pulsoEsq); 
    mDireito.writeMicroseconds(pararMDireito + pulsoDir); 
  
}

 

void ControleMovimento::giraAte(unsigned long contE, unsigned long contD){
  int pE = 0; 
  int pD = 0; 
  if ( contaGE.contaAte(contE)) {
    pE = incEsq; 
  }
  if ( contaGE.contaAte(contD)) {
    pD = incDir; 
  }
  moveMotores(pE,pD); 
  Serial.println(contaGE.velocidadeRoda()); 

}

/* Deve ser chamada no loop principal */
void ControleMovimento::atualizaSensores(){
  contaGE.atualiza();
  contaGD.atualiza(); 

}

 
