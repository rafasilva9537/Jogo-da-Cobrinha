
//aqui seria o loop do menu
ENQUANTO(VERDADE) {
  SE(escolha == "novo jogo"){
    //aqui dentro ficaria o jogo, o loop dele, se a escolha for novo jogo entra no jogo
    ENQUANTO(VERDADE){
      //JOGUINHO DA COBRA COMPLETO
    }
  }
  SE(escolha == "créditos"){
    printf("Créditos")
    SE(escolha == "voltar para o menu"){
      continue; //ou seja, volta pra o início do loop, na linha 3, lembra, continue faz o mesmo que o break mas não encerra o loop, apenas sai do loop atual, do loop que você escolheu entrar nos créditos
    }
  }
}