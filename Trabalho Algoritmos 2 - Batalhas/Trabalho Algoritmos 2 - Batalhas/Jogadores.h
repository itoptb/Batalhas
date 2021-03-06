#pragma once
#ifndef JOGADORES_H
#define JOGADORES_H
#include <iostream>
#include <string>
#include "monstros.h"
#include "auxiliar.h"
using namespace std;

struct Jogador {
	string nome;
	monstro monstros[2];
	int nivel;
};

int jogador_atribuiMonstroInicial(Jogador jogador)
{
	for (int i = 0; i < 2; i++)
	{
		if (jogador.monstros[i].hp > 0)
			return i;
	}
	
	return -1;
}

int jogador_trocarMonstro(Jogador jogador, int monstroAtual)
{
	for (int i=0;i<2;i++)
	{
		if (jogador.monstros[i].hp > 0 && i != monstroAtual)
		{
			return i;
		}
	}
	return -1;
}

void jogador_resetaMonstros(Jogador &jogador)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			jogador.monstros[i].hp = 100;
			jogador.monstros[i].poderes[j].auxTurnoAtaque = -1;
			jogador.monstros[i].poderes[j].disponivel = true;
			jogador.monstros[i].poderes[j].auxQuantidadeVezesUso = 0;
		}
	}
}

void jogador_atualizaEstatisticasTurno(Jogador &jogador, int turnoAtual)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int teste = turnoAtual - jogador.monstros[i].poderes[j].auxTurnoAtaque;
			if (((teste) >= jogador.monstros[i].poderes[j].turnoAtaque) && !jogador.monstros[i].poderes[j].disponivel)
			{
				jogador.monstros[i].poderes[j].disponivel = true;
			}
		}
	}
}

void jogadores_inicializarJogadores(Jogador &player, Jogador &inimigo1, Jogador &inimigo2, Jogador &inimigo3, Jogador &inimigo4)
{
	monstro
		tangath_toborn,
		maxxor,
		intress,
		rellim,
		donmar,
		intress2,
		ekuud,
		frafdo,
		bylkian,
		titanix;

	monstro_inicializarMonstro(
		tangath_toborn,
		maxxor,
		intress,
		rellim,
		donmar,
		intress2,
		ekuud,
		frafdo,
		bylkian,
		titanix);

	monstro monstros[10] = {
		tangath_toborn,
		maxxor,
		intress,
		rellim,
		donmar,
		intress2,
		ekuud,
		frafdo,
		bylkian,
		titanix };
	
	int monstrosAtribuidos[10] = {0};
	int idMonstro;
	//monstrosAtribuidos[0] = idMonstro;
	bool procuraValor = true;
	
	for (int j = 0; j < 10; j++)
	{
		procuraValor = true;
		while (procuraValor)
		{
			idMonstro = numeroAleatorio(1, 10);
			procuraValor = false;
			for (int i = 0; i < 10; i++)
			{
				if (monstrosAtribuidos[i] == idMonstro)
				{
					procuraValor = true;
					//i = j;
				}
			}
		}
		monstrosAtribuidos[j] = idMonstro;
	}

	

	player.nome = "Testando";
	player.nivel = 50;
	player.monstros[0] = monstro_setaMonstroPorId(monstros, 10, monstrosAtribuidos[0]);
	player.monstros[1] = monstro_setaMonstroPorId(monstros, 10, monstrosAtribuidos[1]);

	inimigo1.nome = "Inimigo 1";
	inimigo1.nivel = 50;
	inimigo1.monstros[0] = monstro_setaMonstroPorId(monstros, 10, monstrosAtribuidos[2]);
	inimigo1.monstros[1] = monstro_setaMonstroPorId(monstros, 10, monstrosAtribuidos[3]);

	inimigo2.nome = "Inimigo 2";
	inimigo2.nivel = 50;
	inimigo2.monstros[0] = monstro_setaMonstroPorId(monstros, 10, monstrosAtribuidos[4]);
	inimigo2.monstros[1] = monstro_setaMonstroPorId(monstros, 10, monstrosAtribuidos[5]);

	inimigo3.nome = "Inimigo 3";
	inimigo3.nivel = 50;
	inimigo3.monstros[0] = monstro_setaMonstroPorId(monstros, 10, monstrosAtribuidos[6]);
	inimigo3.monstros[1] = monstro_setaMonstroPorId(monstros, 10, monstrosAtribuidos[7]);

	inimigo4.nome = "Inimigo 4";
	inimigo4.nivel = 50;
	inimigo4.monstros[0] = monstro_setaMonstroPorId(monstros, 10, monstrosAtribuidos[8]);
	inimigo4.monstros[1] = monstro_setaMonstroPorId(monstros, 10, monstrosAtribuidos[9]);

}


#endif