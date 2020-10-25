//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     Red-Black Tree - public interface tests
//
// $NoKeywords: $ivs_project_1 $black_box_tests.cpp
// $Author:     Pavel Bobcik <xbobci03@stud.fit.vutbr.cz>
// $Date:       $2020-02-28
//============================================================================//
/**
 * @file black_box_tests.cpp
 * @author Pavel Bobcik
 * 
 * @brief Implementace testu binarniho stromu.
 */

#include <vector>

#include "gtest/gtest.h"

#include "red_black_tree.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy Red-Black Tree, testujte nasledujici:
// 1. Verejne rozhrani stromu
//    - InsertNode/DeleteNode a FindNode
//    - Chovani techto metod testuje pro prazdny i neprazdny strom.
// 2. Axiomy (tedy vzdy platne vlastnosti) Red-Black Tree:
//    - Vsechny listove uzly stromu jsou *VZDY* cerne.
//    - Kazdy cerveny uzel muze mit *POUZE* cerne potomky.
//    - Vsechny cesty od kazdeho listoveho uzlu ke koreni stromu obsahuji
//      *STEJNY* pocet cernych uzlu.
//============================================================================//

class BinaryTreeTesting : public ::testing::Test{
    protected:
        BinaryTree binaryTree = BinaryTree();
    
        //Vytvoříme pole prvků
        int values[5] = {1, 2, 3, 4, 5};
};

class EmptyTree : public BinaryTreeTesting{
};

class NonEmptyTree : public BinaryTreeTesting{

    protected:
        virtual void SetUp() {
            //Pomocí foreach cyklu vložíme prvky do stromu
            for(int key : values){
                binaryTree.InsertNode(key);
            }
        }
};

class TreeAxioms : public BinaryTreeTesting{

    protected:
        virtual void SetUp() {
            
            for(int key : values){
                binaryTree.InsertNode(key);
            }
        }
};

TEST_F(EmptyTree, InsertNode){
    //Vytvoření kořenového uzlu
    std::pair<bool, BinaryTree::Node_t *> pairEmptyT = binaryTree.InsertNode(2);
    BinaryTree::Node_t *nodeEmptyT = pairEmptyT.second;
    ASSERT_TRUE(nodeEmptyT != NULL);
    EXPECT_TRUE(pairEmptyT.first);
    
    //Kontrola očekávaných vlastností kořenového uzlu
    EXPECT_EQ(nodeEmptyT->key, 2);
    EXPECT_EQ(nodeEmptyT->color, BinaryTree::BLACK);
    EXPECT_TRUE(nodeEmptyT->pParent == NULL);
    EXPECT_TRUE(nodeEmptyT->pRight != NULL);
    EXPECT_TRUE(nodeEmptyT->pLeft != NULL);
    
    //Vytvoření poduzlu
    std::pair<bool, BinaryTree::Node_t *> pairEmptyT2 = binaryTree.InsertNode(1);
    BinaryTree::Node_t *nodeEmptyT2 = pairEmptyT2.second;
    ASSERT_TRUE(nodeEmptyT2 != NULL);
    EXPECT_TRUE(pairEmptyT2.first);
    
    //Kontrola očekávaných vlastností poduzlu
    EXPECT_EQ(nodeEmptyT2->key, 1);
    EXPECT_EQ(nodeEmptyT2->color, BinaryTree::RED);
    EXPECT_TRUE(nodeEmptyT2->pRight != NULL);
    EXPECT_TRUE(nodeEmptyT2->pLeft != NULL);
    EXPECT_TRUE(nodeEmptyT2->pParent != NULL);
    EXPECT_TRUE(nodeEmptyT2->pParent->key == 2);
    
    //Kontrola očekávaného chování pravého poduzlu (uzlu key == 1)
    BinaryTree::Node_t *nodeET2Right = nodeEmptyT2->pRight;
    ASSERT_TRUE(nodeET2Right != NULL);
    EXPECT_EQ(nodeET2Right->color, BinaryTree::BLACK);
    EXPECT_TRUE(nodeET2Right->pRight == NULL);
    EXPECT_TRUE(nodeET2Right->pParent != NULL);
    EXPECT_TRUE(nodeET2Right->pParent->key == 1);
    
    //Kontrola očekávaného chování levého poduzlu (uzlu key == 1)
    BinaryTree::Node_t *nodeET2Left = nodeEmptyT2->pRight;
    ASSERT_TRUE(nodeET2Left != NULL);
    EXPECT_EQ(nodeET2Left->color, BinaryTree::BLACK);
    EXPECT_TRUE(nodeET2Left->pRight == NULL);
    EXPECT_TRUE(nodeET2Left->pParent != NULL);
    EXPECT_TRUE(nodeET2Left->pParent->key == 1);
    
    //Kontrola očekávaného chování pravého poduzlu (uzlu key == 2)
    BinaryTree::Node_t *nodeETRight = nodeEmptyT->pRight;
    ASSERT_TRUE(nodeETRight != NULL);
    EXPECT_EQ(nodeETRight->color, BinaryTree::BLACK);
    EXPECT_TRUE(nodeETRight->pRight == NULL);
    EXPECT_TRUE(nodeETRight->pLeft == NULL);
    EXPECT_TRUE(nodeETRight->pParent != NULL);
    EXPECT_TRUE(nodeETRight->pParent->key == 2);
    
    //Vytvoření pravého poduzlu (uzlu key == 2)
    std::pair<bool, BinaryTree::Node_t *> pairEmptyT3 = binaryTree.InsertNode(5);
    BinaryTree::Node_t *nodeEmptyT3 = pairEmptyT3.second;
    ASSERT_TRUE(nodeEmptyT3 != NULL);
    EXPECT_TRUE(pairEmptyT3.first);
    
    //Kontrola očekávaných vlastností poduzlu (uzlu key = 2)
    EXPECT_EQ(nodeEmptyT3->key, 5);
    EXPECT_EQ(nodeEmptyT3->color, BinaryTree::RED);
    EXPECT_TRUE(nodeEmptyT3->pRight != NULL);
    EXPECT_TRUE(nodeEmptyT3->pLeft != NULL);
    EXPECT_TRUE(nodeEmptyT3->pParent != NULL);
    EXPECT_TRUE(nodeEmptyT3->pParent->key == 2);
    
    //Kontrola očekávaného chování pravého poduzlu (uzlu key == 5)
    BinaryTree::Node_t *nodeET3Right = nodeEmptyT3->pRight;
    ASSERT_TRUE(nodeET3Right != NULL);
    EXPECT_EQ(nodeET3Right->color, BinaryTree::BLACK);
    EXPECT_TRUE(nodeET3Right->pRight == NULL);
    EXPECT_TRUE(nodeET3Right->pParent != NULL);
    EXPECT_TRUE(nodeET3Right->pParent->key == 5);

    //Vytvoření uzlu s již použitým KEY (Používáme key == 2 - kořenový uzel)
    std::pair<bool, BinaryTree::Node_t *> pairEmptyT4 = binaryTree.InsertNode(2);
    BinaryTree::Node_t *nodeEmptyT4 = pairEmptyT4.second;
    ASSERT_TRUE(nodeEmptyT4 != NULL);
    EXPECT_FALSE(pairEmptyT4.first);
    EXPECT_TRUE(nodeEmptyT4->pParent == NULL);
    
    //Vytvoření uzlu s hodnotou 0
    std::pair<bool, BinaryTree::Node_t *> pairEmptyT5 = binaryTree.InsertNode(0);
    BinaryTree::Node_t *nodeEmptyT5 = pairEmptyT5.second;
    ASSERT_TRUE(nodeEmptyT5 != NULL);
    EXPECT_EQ(nodeEmptyT5->color, BinaryTree::RED);
    EXPECT_TRUE(pairEmptyT5.first);
    EXPECT_TRUE(nodeEmptyT5->pParent != NULL);
    EXPECT_TRUE(nodeEmptyT5->pParent->key == 1);
    
    //Vytvoření uzlu s zápornou hodnotou
    std::pair<bool, BinaryTree::Node_t *> pairEmptyT6 = binaryTree.InsertNode(-1);
    BinaryTree::Node_t *nodeEmptyT6 = pairEmptyT6.second;
    ASSERT_TRUE(nodeEmptyT6 != NULL);
    EXPECT_EQ(nodeEmptyT6->color, BinaryTree::RED);
    EXPECT_TRUE(pairEmptyT6.first);
    EXPECT_TRUE(nodeEmptyT6->pParent != NULL);
    EXPECT_TRUE(nodeEmptyT6->pParent->key == 0);
    
}

TEST_F(NonEmptyTree, InsertNode){
    //Vytvoření uzlu s již existujícím key a otestování (key == 2 - korenovy uzel)
    std::pair<bool, BinaryTree::Node_t *> pairNonEmptyT = binaryTree.InsertNode(2);
    BinaryTree::Node_t *nodeNonEmptyT = pairNonEmptyT.second;
    ASSERT_TRUE(nodeNonEmptyT != NULL);
    EXPECT_EQ(nodeNonEmptyT->color, BinaryTree::BLACK);
    EXPECT_TRUE(nodeNonEmptyT->pParent == NULL);
    EXPECT_TRUE(nodeNonEmptyT->pRight != NULL);
    EXPECT_TRUE(nodeNonEmptyT->pLeft != NULL);
    
    //Otestojeme jeho levý poduzel
    BinaryTree::Node_t *nodeNET1 = nodeNonEmptyT->pLeft;
    ASSERT_TRUE(nodeNET1 != NULL);
    EXPECT_EQ(nodeNET1->key, 1);
    EXPECT_EQ(nodeNET1->color, BinaryTree::BLACK);
    EXPECT_TRUE(nodeNET1->pLeft != NULL);
    EXPECT_TRUE(nodeNET1->pRight != NULL);
    EXPECT_TRUE(nodeNET1->pParent != NULL);
    EXPECT_EQ(nodeNET1->pParent->key, 2);
    
    //Otestujeme listový uzel levého poduzlu
    BinaryTree::Node_t *nodeNET1Left = nodeNET1->pLeft;
    ASSERT_TRUE(nodeNET1Left != NULL);
    EXPECT_EQ(nodeNET1Left->color, BinaryTree::BLACK);
    EXPECT_TRUE(nodeNET1Left->pRight == NULL);
    EXPECT_TRUE(nodeNET1Left->pParent != NULL);
    EXPECT_EQ(nodeNET1Left->pParent->key, 1);
    
    //Otestuje pravý poduzel kořenového uzlu
    BinaryTree::Node_t *nodeNET2 = nodeNonEmptyT->pRight;
    ASSERT_TRUE(nodeNET2 != NULL);
    EXPECT_EQ(nodeNET2->key, 4);
    EXPECT_EQ(nodeNET2->color, BinaryTree::BLACK);
    EXPECT_TRUE(nodeNET2->pLeft != NULL);
    EXPECT_TRUE(nodeNET2->pParent != NULL);
    EXPECT_TRUE(nodeNET2->pRight != NULL);
    EXPECT_EQ(nodeNET2->pParent->key, 2);
    
    //Otestujeme levý uzel (uzlu key == 4)
    BinaryTree::Node_t *nodeNET3 = nodeNET2->pLeft;
    ASSERT_TRUE(nodeNET3 != NULL);
    EXPECT_EQ(nodeNET3->key, 3);
    EXPECT_EQ(nodeNET3->color, BinaryTree::RED);
    EXPECT_TRUE(nodeNET3->pRight != NULL);
    EXPECT_TRUE(nodeNET3->pLeft != NULL);
    EXPECT_TRUE(nodeNET3->pParent != NULL);
    EXPECT_EQ(nodeNET3->pParent->key, 4);
    
    //Otestujeme pravý uzel (uzlu key == 4)
    BinaryTree::Node_t *nodeNET4 = nodeNET2->pRight;
    ASSERT_TRUE(nodeNET4 != NULL);
    EXPECT_EQ(nodeNET4->key, 5);
    EXPECT_EQ(nodeNET4->color, BinaryTree::RED);
    EXPECT_TRUE(nodeNET4->pRight != NULL);
    EXPECT_TRUE(nodeNET4->pLeft != NULL);
    EXPECT_TRUE(nodeNET4->pParent != NULL);
    EXPECT_EQ(nodeNET4->pParent->key, 4);
    
    //Přidáme a otestujeme novou hodnotu
    std::pair<bool, BinaryTree::Node_t *> pairNET5 = binaryTree.InsertNode(6);
    BinaryTree::Node_t *nodeNET5 = pairNET5.second;
    ASSERT_TRUE(nodeNET5 != NULL);
    EXPECT_TRUE(pairNET5.first);
    EXPECT_EQ(nodeNET5->color, BinaryTree::RED);
    EXPECT_TRUE(nodeNET5->pRight != NULL);
    EXPECT_TRUE(nodeNET5->pLeft != NULL);
    EXPECT_TRUE(nodeNET5->pParent != NULL);
    EXPECT_EQ(nodeNET5->pParent->key, 5);
    
    //Vytvoření uzlu s zápornou hodnotou
    std::pair<bool, BinaryTree::Node_t *> pairNET6 = binaryTree.InsertNode(-7);
    BinaryTree::Node_t *nodeNET6 = pairNET6.second;
    ASSERT_TRUE(nodeNET6 != NULL);
    EXPECT_EQ(nodeNET6->color, BinaryTree::RED);
    EXPECT_TRUE(pairNET6.first);
    EXPECT_TRUE(nodeNET6->pParent != NULL);
    EXPECT_TRUE(nodeNET6->pParent->key == 1);
}

TEST_F(EmptyTree, DeleteNode){
    EXPECT_FALSE(binaryTree.DeleteNode(1));
    EXPECT_FALSE(binaryTree.DeleteNode(0));
    EXPECT_FALSE(binaryTree.DeleteNode(-1));
}

TEST_F(NonEmptyTree, DeleteNode){
    //Vymažeme hodnotu stromu
    EXPECT_TRUE(binaryTree.DeleteNode(1));
    //Otestujeme vymazání stejné hodnoty znovu
    EXPECT_FALSE(binaryTree.DeleteNode(1));
    //Nyní hodnoty, jenž nebyly přidány do stromu
    EXPECT_FALSE(binaryTree.DeleteNode(10));
    EXPECT_FALSE(binaryTree.DeleteNode(0));
    EXPECT_FALSE(binaryTree.DeleteNode(-1));
}

TEST_F(EmptyTree, FindNode){
    EXPECT_TRUE(binaryTree.FindNode(1) == NULL);
    EXPECT_TRUE(binaryTree.FindNode(0) == NULL);
    EXPECT_TRUE(binaryTree.FindNode(-1) == NULL);
}

TEST_F(NonEmptyTree, FindNode){
    EXPECT_TRUE(binaryTree.FindNode(10) == NULL);
    EXPECT_TRUE(binaryTree.FindNode(0) == NULL);
    EXPECT_TRUE(binaryTree.FindNode(-1) == NULL);
    EXPECT_TRUE(binaryTree.FindNode(1) != NULL);
}

TEST_F(TreeAxioms, Axiom1){
    std::vector<BinaryTree::Node_t *> outLeafNodes;
    binaryTree.GetLeafNodes(outLeafNodes);
    
    for(BinaryTree::Node_t *leafNode : outLeafNodes){
        ASSERT_EQ(leafNode->color, BinaryTree::BLACK);
    }
}

TEST_F(TreeAxioms, Axiom2){
    std::vector<BinaryTree::Node_t *> outNonLeafNodes;
    binaryTree.GetNonLeafNodes(outNonLeafNodes);
    
    for(BinaryTree::Node_t *nonLeafNode : outNonLeafNodes){
        if(nonLeafNode->color == BinaryTree::RED){
            ASSERT_EQ(nonLeafNode->pLeft->color, BinaryTree::BLACK);
            ASSERT_EQ(nonLeafNode->pRight->color, BinaryTree::BLACK);
        }
    }
}

TEST_F(TreeAxioms, Axiom3){
    std::vector<BinaryTree::Node_t *> outLeafNodes;
    binaryTree.GetLeafNodes(outLeafNodes);
    int blackNodes = 0;
    int numberOfPaths = -1;
    int leafs = sizeof(outLeafNodes);
    int arrayLeafs[leafs];
    
    for(BinaryTree::Node_t *currentNode : outLeafNodes){
        numberOfPaths ++;
        while(currentNode != binaryTree.GetRoot()){
            if(currentNode->color == BinaryTree::BLACK){
                blackNodes ++;
            }
            currentNode = currentNode->pParent;
        }
        arrayLeafs[numberOfPaths] = blackNodes;
        blackNodes = 0;
    }
    
    for(int i = 0; i < numberOfPaths; i++){
        ASSERT_EQ(arrayLeafs[i], arrayLeafs[i+1]);
    }
}


/*** Konec souboru black_box_tests.cpp ***/
