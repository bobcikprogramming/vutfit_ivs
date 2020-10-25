//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Test Driven Development - priority queue code
//
// $NoKeywords: $ivs_project_1 $tdd_code.cpp
// $Author:     Pavel Bobcik <xbobci03@stud.fit.vutbr.cz>
// $Date:	$2020-03-02
//============================================================================//
/**
 * @file tdd_code.cpp
 * @author Pavel Bobcik
 * 
 * @brief Implementace metod tridy prioritni fronty.
 */

#include <stdlib.h>
#include <stdio.h>

#include "tdd_code.h"

//============================================================================//
// ** ZDE DOPLNTE IMPLEMENTACI **
//
// Zde doplnte implementaci verejneho rozhrani prioritni fronty (Priority Queue)
// 1. Verejne rozhrani fronty specifikovane v: tdd_code.h (sekce "public:")
//    - Konstruktor (PriorityQueue()), Destruktor (~PriorityQueue())
//    - Metody Insert/Remove/Find a GetHead
//    - Pripadne vase metody definovane v tdd_code.h (sekce "protected:")
//
// Cilem je dosahnout plne funkcni implementace prioritni fronty implementovane
// pomoci tzv. "double-linked list", ktera bude splnovat dodane testy 
// (tdd_tests.cpp).
//============================================================================//

PriorityQueue::PriorityQueue()
{
    root = NULL;
}

PriorityQueue::~PriorityQueue()
{
    Element_t *toDelete = GetHead();
    while(toDelete != NULL){
        Element_t *nextPos = toDelete->pNext;
        delete toDelete;
        toDelete = nextPos;
    }
}

void PriorityQueue::Insert(int value)
{
    Element_t *element = GetHead();
    if(element == NULL){
        root = AddNewElement(value, NULL, NULL);
    }else{
        while(element != NULL){ 
             if(element->pPrev == NULL && element->pNext == NULL){
                if(element->value < value){
                    element->pNext = AddNewElement(value, element, NULL);
                }else{
                    root = AddNewElement(value, NULL, element);
                    element->pPrev = root;
                }
                break;
            }else if(element->pPrev == NULL && element->pNext != NULL){
                if(element->value > value){
                    root = AddNewElement(value, NULL, element);
                    element->pPrev = root;
                    break;
                }
            }else if(element->pPrev != NULL && element->pNext == NULL){
                if(element->value > value){
                    element->pPrev->pNext = AddNewElement(value, element->pPrev, element);
                    element->pPrev = element->pPrev->pNext;
                    break;
                 }else{
                    element->pNext = AddNewElement(value, element, NULL);
                    break;
                }
            }else if(element->value <= value && element->pNext->value >= value){
                Element_t *newE = AddNewElement(value, element, element->pNext);
                element->pNext->pPrev = newE;
                element->pNext = newE;
                break;
            }
            element = element->pNext;
        }
    }
}

bool PriorityQueue::Remove(int value)
{
   if(Element_t *element = Find(value)){
        if(element->pPrev == NULL && element->pNext == NULL){
            root = NULL;
        }else if(element->pPrev == NULL && element->pNext != NULL){
            element->pNext->pPrev = NULL;
            root = element->pNext;
        }else if(element->pPrev != NULL && element->pNext == NULL){
       	    element->pPrev->pNext = NULL;
        }else{
            element->pNext->pPrev = element->pPrev;
            element->pPrev->pNext = element->pNext;
        }
        delete element;
        return true;
    }else{
        return false;
    }
}

PriorityQueue::Element_t *PriorityQueue::Find(int value)
{
    for(Element_t *element = GetHead(); element != NULL; element = element->pNext){
        if(element->value == value){
            return element;
        }
    }
    return NULL;
}

PriorityQueue::Element_t *PriorityQueue::GetHead()
{
    return root;
}

PriorityQueue::Element_t *PriorityQueue::AddNewElement(int value, Element_t *pPrev, Element_t *pNext){
    Element_t *element = new Element_t();
    element->value = value;
    element->pPrev = pPrev;
    element->pNext = pNext;
    
    return element;
}

/*** Konec souboru tdd_code.cpp ***/
