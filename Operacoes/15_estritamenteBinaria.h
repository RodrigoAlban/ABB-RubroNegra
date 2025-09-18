#ifndef ESTRITAMENTE_BINARIA_H
#define ESTRITAMENTE_BINARIA_H

/* Verifica recursivamente se cada noh possui exatamente 2 filhos ou nenhum (folha). 
   Considera nulos tanto ponteiros NULL quanto o noh sentinela da rubro-negra. */
static int estritamenteBinariaRec(pNohArvore n, pNohArvore sentinela){
    if (n == NULL || n == sentinela)
        return 1; // vazio é estritamente binária

    int esqVazia = (n->esquerda == NULL) || (n->esquerda == sentinela);
    int dirVazia = (n->direita  == NULL) || (n->direita  == sentinela);

    // exatamente um filho presente => não é estritamente binária
    if (esqVazia ^ dirVazia)
        return 0;

    // ambos vazios (folha) ou ambos presentes: verifica subárvores
    return estritamenteBinariaRec(n->esquerda, sentinela) &&
           estritamenteBinariaRec(n->direita,  sentinela);
}

int estritamenteBinaria (pDArvore arvore){
    if (arvore == NULL)
        return 1; // por convenção, árvore inexistente é estritamente binária

    return estritamenteBinariaRec(arvore->raiz, arvore->sentinela);
}

#endif
