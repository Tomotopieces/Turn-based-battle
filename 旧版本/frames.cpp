#include"frames.h"


entity temp_p, temp_e;//��ʱ�ṹ
entity player_d{ "empty",20,2,0,1,20,1,0,50 };
entity player{};
entity enemy[]{
	{ "ħ��",50,3,0,2,50,99,100,0,
	"     ���v                       �u��\n     �� ��                     �� ��\n     �� ��      __      __     �� ��\n     ��  �v __�u   �v __�u   �v __�u  ��\n      �v ____              ____�u\n           ��      �U      ��\n            �v     �U     �u\n             ��    �p    ��\n              �v   __  �u\n               �� �� �� ��\n                �v�� ���u\n"
	},
	{ "С͵",20,1,0,1,5,1,10,0,
	"               �u �v     �u �v\n               �v   �v �u �u �u\n               �u �v �u �v �u\n             �u�u    �v �u �v\n           �u�u        �v   �v\n          ����         �u �v �u\n          ����       �u\n          ����     �u\n          ����   �u\n          ���� �u\n          ���u\n"
	}
};

equipment sword{ "��ʴ�̽�",1,0,15,weapon };
equipment shield{ "ľ��Բ��",0,1,15,armor };