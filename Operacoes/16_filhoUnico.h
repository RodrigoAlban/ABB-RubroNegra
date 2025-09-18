#ifndef FILHO_UNICO_H
#define FILHO_UNICO_H

/* Conta quantos nohs possuem exatamente um filho (esquerdo ou direito),
   considerando NULL e sentinela como ausentes. */
static int filhoUnicoRec(pNohArvore n, pNohArvore sentinela){
    if (n == NULL || n == sentinela)
        return 0;

    int esqVazia = (n->esquerda == NULL) || (n->esquerda == sentinela);
    int dirVazia = (n->direita  == NULL) || (n->direita  == sentinela);

    int contaAqui = (esqVazia ^ dirVazia) ? 1 : 0;

    return contaAqui +
           filhoUnicoRec(n->esquerda, sentinela) +
           filhoUnicoRec(n->direita,  sentinela);
}

int filhoUnico (pDArvore arvore){
    if (arvore == NULL)
        return 0;
    return filhoUnicoRec(arvore->raiz, arvore->sentinela);
}

#endif
