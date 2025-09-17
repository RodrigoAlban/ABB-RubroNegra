#ifndef IGUAIS_ARVORE_H
#define IGUAIS_ARVORE_H

/*
 Retorna 1 se as duas arvores sao iguais (mesma estrutura e mesma informacao em cada noh),
 caso contrario retorna 0. Usa a funcao de comparacao fc: considera iguais quando fc(a,b) == 0.
*/
static int iguaisNoRec(pNohArvore n1, pNohArvore n2, pNohArvore sent1, pNohArvore sent2, FuncaoComparacao fc){
    // ambos nulos ou sentinelas => iguais
    int vazio1 = (n1 == NULL) || (n1 == sent1);
    int vazio2 = (n2 == NULL) || (n2 == sent2);
    if (vazio1 && vazio2) return 1;
    if (vazio1 || vazio2) return 0;

    // compara info com fc: iguais quando fc(x,y) == 0 e fc(y,x) == 0 (robusto para comparadores assimetricos)
    if (!(fc(n1->info, n2->info) == 0 && fc(n2->info, n1->info) == 0))
        return 0;

    // compara subarvores esquerda e direita
    if (!iguaisNoRec(n1->esquerda, n2->esquerda, sent1, sent2, fc)) return 0;
    if (!iguaisNoRec(n1->direita,  n2->direita,  sent1, sent2, fc)) return 0;

    // opcional: comparar cores se for rubro-negra; se quiser ignorar propriedades de balanceamento, comente a linha abaixo
    if (n1->cor != n2->cor) return 0;

    return 1;
}

int iguais(pDArvore arvore1, pDArvore arvore2, FuncaoComparacao fc){
    if (arvore1 == NULL && arvore2 == NULL) return 1;
    if (arvore1 == NULL || arvore2 == NULL) return 0;

    return iguaisNoRec(arvore1->raiz, arvore2->raiz, arvore1->sentinela, arvore2->sentinela, fc);
}

#endif
