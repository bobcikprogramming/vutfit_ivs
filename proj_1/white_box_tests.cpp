//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     Pavel Bobcik <xbobci03@stud.fit.vutbr.cz>
// $Date:	$2020-03-01
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author Pavel Bobcik
 * 
 * @brief Implementace testu prace s maticemi.
 */

#include "gtest/gtest.h"
#include "white_box_code.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy operaci nad maticemi. Cilem testovani je:
// 1. Dosahnout maximalniho pokryti kodu (white_box_code.cpp) testy.
// 2. Overit spravne chovani operaci nad maticemi v zavislosti na rozmerech 
//    matic.
//============================================================================//

namespace whiteBoxTest{
    class TestingMatrix : public ::testing::Test{
        
    protected:
        Matrix getMatrixSize1x1(){
            return Matrix();
        }
        
        Matrix getMatrixSize2x2(){
            return Matrix(2, 2);
        }
        
        Matrix getMatrixSize2x3(){
            return Matrix(2, 3);
        }
        
        Matrix getMatrixSize3x3(){
            return Matrix(3, 3);
        }
        
        Matrix getMatrixSize4x4(){
            return Matrix(4, 4);
        }
        
        Matrix getMatrixSize5x4(){
            return Matrix(5, 4);
        }
        
        Matrix getMatrixSize5x6(){
            return Matrix(5, 6);
        }
    };
    
    TEST_F(TestingMatrix, ConstractMatrix){
        //Otestujeme úspěšné vytvoření matic
        EXPECT_NO_THROW(Matrix());
        EXPECT_NO_THROW(Matrix(1, 1));
        EXPECT_NO_THROW(Matrix(2, 2));
        EXPECT_NO_THROW(Matrix(3, 3));
        EXPECT_NO_THROW(Matrix(4, 4));
        EXPECT_NO_THROW(Matrix(5, 6));
        EXPECT_NO_THROW(Matrix(6, 3));
        
        //Otestujeme neúspěšné vytvoření matice
        EXPECT_ANY_THROW(Matrix(0, 0));
        EXPECT_ANY_THROW(Matrix(0, 1));
        EXPECT_ANY_THROW(Matrix(1, 0));
        EXPECT_ANY_THROW(Matrix(1, -1));
        
        //Otestujeme vytvoření velké matice - bohužel výkon IVS serveru nechtěl matici otestovat
        // EXPECT_ANY_THROW(Matrix(9999999, 9999999));
    }
    
    TEST_F(TestingMatrix, SetValuesToMatrixSize1x1){
        Matrix matrix = getMatrixSize1x1();
        //Otestujeme platnou matici
        EXPECT_TRUE(matrix.set(0, 0, 1));
        EXPECT_TRUE(matrix.set(0, 0, 2));
        
        //Otestujeme neplatnou matici
        EXPECT_FALSE(matrix.set(0, 1, 1));
        EXPECT_FALSE(matrix.set(0, -1, 1));
    }
    
    TEST_F(TestingMatrix, SetValuesToMatrixSize2x2){
        Matrix matrix = getMatrixSize2x2();
        //Otestujeme platnou matici
        EXPECT_TRUE(matrix.set(0, 0, 1));
        EXPECT_TRUE(matrix.set(0, 1, 1));
        EXPECT_TRUE(matrix.set(1, 0, 2));
        EXPECT_TRUE(matrix.set(1, 1, 3));
        
        //Otestujeme neplatnou matici
        EXPECT_FALSE(matrix.set(0, 2, 1));
        EXPECT_FALSE(matrix.set(0, -1, 1));
    }
    
    TEST_F(TestingMatrix, SetValuesToMatrixSize3x3){
        Matrix matrix = getMatrixSize3x3();
        //Otestujeme platnou matici
        EXPECT_TRUE(matrix.set(0, 0, 1));
        EXPECT_TRUE(matrix.set(0, 2, 1));
        EXPECT_TRUE(matrix.set(1, 0, 2));
        EXPECT_TRUE(matrix.set(1, 2, 2));
        EXPECT_TRUE(matrix.set(2, 0, 3));
        EXPECT_TRUE(matrix.set(2, 2, 3));
        
        //Otestujeme neplatnou matici
        EXPECT_FALSE(matrix.set(0, 3, 1));
        EXPECT_FALSE(matrix.set(0, -1, 1));
    }
    
    TEST_F(TestingMatrix, SetValuesToMatrixSize5x4){
        Matrix matrix = getMatrixSize5x4();
        //Otestujeme platnou matici
        EXPECT_TRUE(matrix.set(0, 0, 1));
        EXPECT_TRUE(matrix.set(0, 3, 1));
        EXPECT_TRUE(matrix.set(1, 0, 2));
        EXPECT_TRUE(matrix.set(1, 3, 2));
        EXPECT_TRUE(matrix.set(2, 0, 3));
        EXPECT_TRUE(matrix.set(2, 3, 3));
        EXPECT_TRUE(matrix.set(3, 0, 4));
        EXPECT_TRUE(matrix.set(3, 3, 4));
        EXPECT_TRUE(matrix.set(4, 0, 5));
        EXPECT_TRUE(matrix.set(4, 3, 5));
        
        //Otestujeme neplatnou matici
        EXPECT_FALSE(matrix.set(0, 4, 1));
        EXPECT_FALSE(matrix.set(0, -1, 1));
    }
    
    TEST_F(TestingMatrix, SetValuesToMatrixSize5x6){
        Matrix matrix = getMatrixSize5x6();
        //Otestujeme platnou matici
        EXPECT_TRUE(matrix.set(0, 0, 1));
        EXPECT_TRUE(matrix.set(0, 5, 1));
        EXPECT_TRUE(matrix.set(1, 0, 2));
        EXPECT_TRUE(matrix.set(1, 5, 2));
        EXPECT_TRUE(matrix.set(2, 0, 3));
        EXPECT_TRUE(matrix.set(2, 5, 3));
        EXPECT_TRUE(matrix.set(3, 0, 4));
        EXPECT_TRUE(matrix.set(3, 5, 4));
        EXPECT_TRUE(matrix.set(4, 0, 5));
        EXPECT_TRUE(matrix.set(4, 5, 5));
        
        //Otestujeme neplatnou matici
        EXPECT_FALSE(matrix.set(0, 6, 1));
        EXPECT_FALSE(matrix.set(0, -1, 1));
    }

    TEST_F(TestingMatrix, SetValuesToMatrixByArray){
        Matrix matrix1x1 = getMatrixSize1x1();
        EXPECT_TRUE(matrix1x1.set(std::vector<std::vector<double>> {{1}}));
        EXPECT_FALSE(matrix1x1.set(std::vector<std::vector<double>> {{0, 0, 0}}));
        
        Matrix matrix2x2 = getMatrixSize2x2();
        EXPECT_TRUE(matrix2x2.set(std::vector<std::vector<double>> {{0.0, 1.0},{-1.0, 2.5}}));
        EXPECT_FALSE(matrix2x2.set(std::vector<std::vector<double>> {{0, 0, 0},{0, 0}}));
        
        Matrix matrix3x3 = getMatrixSize3x3();
        EXPECT_TRUE(matrix3x3.set(std::vector<std::vector<double>> {{1, 2, 3},{4, 5, 6}, {7, 8, 9}}));
        EXPECT_FALSE(matrix3x3.set(std::vector<std::vector<double>> {{0, 0, 0},{0}}));
        
        Matrix matrix5x4 = getMatrixSize5x4();
        EXPECT_TRUE(matrix5x4.set(std::vector<std::vector<double>> {{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4}}));
        EXPECT_FALSE(matrix5x4.set(std::vector<std::vector<double>> {{0, 0, 0},{0}}));
        
        Matrix matrix5x6 = getMatrixSize5x6();
        EXPECT_TRUE(matrix5x6.set(std::vector<std::vector<double>> {{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6}}));
        EXPECT_FALSE(matrix5x6.set(std::vector<std::vector<double>> {{0, 0, 0},{0}}));
    }
    
    TEST_F(TestingMatrix, GetValueFromMatrix){
        Matrix matrix2x2 = getMatrixSize2x2();
        ASSERT_TRUE(matrix2x2.set(std::vector<std::vector<double>> {{1, 2},{3, 4}}));
        EXPECT_NO_THROW(matrix2x2.get(1, 1));
        EXPECT_EQ(matrix2x2.get(1, 1), 4);
        EXPECT_NE(matrix2x2.get(1, 1), 0);
        EXPECT_ANY_THROW(matrix2x2.get(2, 2));
        
        Matrix matrix5x4 = getMatrixSize5x4();
        ASSERT_TRUE(matrix5x4.set(std::vector<std::vector<double>> {{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4}}));
        EXPECT_EQ(matrix5x4.get(2, 3), 4);
        EXPECT_NE(matrix5x4.get(2, 3), 0);
        EXPECT_ANY_THROW(matrix5x4.get(-1, 2));
        
        Matrix matrix5x6 = getMatrixSize5x6();
        ASSERT_TRUE(matrix5x6.set(std::vector<std::vector<double>> {{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6}}));
        EXPECT_EQ(matrix5x6.get(1, 2), 3);
        EXPECT_NE(matrix5x6.get(4, 3), 0);
        EXPECT_ANY_THROW(matrix5x6.get(-1, 80));
    }
    
    TEST_F(TestingMatrix, CompareMatrix){
        Matrix matrix2x2First = getMatrixSize2x2();
        Matrix matrix2x2Second = getMatrixSize2x2();
        Matrix matrix2x2Third = getMatrixSize2x2();
        
        Matrix matrix5x4First = getMatrixSize5x4();
        Matrix matrix5x4Second = getMatrixSize5x4();
        Matrix matrix5x4Third = getMatrixSize5x4();
        
        Matrix matrix5x6First = getMatrixSize5x6();
        Matrix matrix5x6Second = getMatrixSize5x6();
        Matrix matrix5x6Third = getMatrixSize5x6();
        
        //Vytvoříme si matice
        ASSERT_TRUE(matrix2x2First.set(std::vector<std::vector<double>> {{1, 2},{-2, -1.5}}));
        ASSERT_TRUE(matrix2x2Second.set(std::vector<std::vector<double>> {{1, 2},{-2, -1.5}}));
        ASSERT_TRUE(matrix2x2Third.set(std::vector<std::vector<double>> {{-1, -2},{2, 1.5}}));
        
        ASSERT_TRUE(matrix5x4First.set(std::vector<std::vector<double>> {{-1.5, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4}}));
        ASSERT_TRUE(matrix5x4Second.set(std::vector<std::vector<double>> {{-1.5, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4}}));
        ASSERT_TRUE(matrix5x4Third.set(std::vector<std::vector<double>> {{1.5, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4}}));
        
        ASSERT_TRUE(matrix5x6First.set(std::vector<std::vector<double>> {{-1, -2.5, -3, -4.5, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6}}));
        ASSERT_TRUE(matrix5x6Second.set(std::vector<std::vector<double>> {{-1, -2.5, -3, -4.5, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6}}));
        ASSERT_TRUE(matrix5x6Third.set(std::vector<std::vector<double>> {{1, 2.5, 3, 4.5, -5, -6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6}}));
        
        //Otestujeme požadovanou funkcionalitu
        ASSERT_NO_THROW(matrix2x2First.operator==(matrix2x2Second));
        ASSERT_NO_THROW(matrix2x2First.operator==(matrix2x2Third));
        EXPECT_TRUE(matrix2x2First.operator==(matrix2x2Second));
        EXPECT_FALSE(matrix2x2First.operator==(matrix2x2Third));
        EXPECT_FALSE(matrix2x2Second.operator==(matrix2x2Third));
        EXPECT_ANY_THROW(matrix2x2First.operator==(matrix5x4First));
        
        ASSERT_NO_THROW(matrix5x4First.operator==(matrix5x4Second));
        ASSERT_NO_THROW(matrix5x4First.operator==(matrix5x4Third));
        EXPECT_TRUE(matrix5x4First.operator==(matrix5x4Second));
        EXPECT_FALSE(matrix5x4First.operator==(matrix5x4Third));
        EXPECT_FALSE(matrix5x4Second.operator==(matrix5x4Third));
        EXPECT_ANY_THROW(matrix5x4First.operator==(matrix2x2First));
        
        ASSERT_NO_THROW(matrix5x6First.operator==(matrix5x6Second));
        ASSERT_NO_THROW(matrix5x6First.operator==(matrix5x6Third));
        EXPECT_TRUE(matrix5x6First.operator==(matrix5x6Second));
        EXPECT_FALSE(matrix5x6First.operator==(matrix5x6Third));
        EXPECT_FALSE(matrix5x6Second.operator==(matrix5x6Third));
        EXPECT_ANY_THROW(matrix5x6First.operator==(matrix5x4First));
    }
    
    TEST_F(TestingMatrix, SumMatrix){
        Matrix matrix2x2First = getMatrixSize2x2();
        Matrix matrix2x2Second = getMatrixSize2x2();
        Matrix matrix2x2Third = getMatrixSize2x2();
        
        Matrix matrix5x4First = getMatrixSize5x4();
        Matrix matrix5x4Second = getMatrixSize5x4();
        Matrix matrix5x4Third = getMatrixSize5x4();
        
        Matrix matrix5x6First = getMatrixSize5x6();
        Matrix matrix5x6Second = getMatrixSize5x6();
        Matrix matrix5x6Third = getMatrixSize5x6();
        
        //Vytvoříme si matice
        ASSERT_TRUE(matrix2x2First.set(std::vector<std::vector<double>> {{1, 2},{-2, -1.5}}));
        ASSERT_TRUE(matrix2x2Second.set(std::vector<std::vector<double>> {{1, 2},{1, 2}}));
        ASSERT_TRUE(matrix2x2Third.set(std::vector<std::vector<double>> {{2, 4},{-1, 0.5}}));
        
        ASSERT_TRUE(matrix5x4First.set(std::vector<std::vector<double>> {{-1.5, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4}}));
        ASSERT_TRUE(matrix5x4Second.set(std::vector<std::vector<double>> {{3, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4}}));
        ASSERT_TRUE(matrix5x4Third.set(std::vector<std::vector<double>> {{1.5, 4, 6, 8},{2, 4, 6, 8},{2, 4, 6, 8},{2, 4, 6, 8},{2, 4, 6, 8}}));
        
        ASSERT_TRUE(matrix5x6First.set(std::vector<std::vector<double>> {{-1, -2.5, -3, -4.5, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6}}));
        ASSERT_TRUE(matrix5x6Second.set(std::vector<std::vector<double>> {{0, 0, 0, 0, 0, 0},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6}}));
        ASSERT_TRUE(matrix5x6Third.set(std::vector<std::vector<double>> {{-1, -2.5, -3, -4.5, 5, 6},{2, 4, 6, 8, 10, 12},{2, 4, 6, 8, 10, 12},{2, 4, 6, 8, 10, 12},{2, 4, 6, 8, 10, 12}}));
        
        //Otestujeme požadovanou funkcionalitu
        ASSERT_NO_THROW(matrix2x2First.operator+(matrix2x2Second));
        ASSERT_NO_THROW(matrix2x2First.operator+(matrix2x2Third));
        EXPECT_EQ(matrix2x2First.operator+(matrix2x2Second), matrix2x2Third);
        EXPECT_FALSE(matrix2x2First.operator+(matrix2x2Third) == matrix2x2Third);
        EXPECT_ANY_THROW(matrix2x2First.operator+(matrix5x4First));
        
        ASSERT_NO_THROW(matrix5x4First.operator+(matrix5x4Second));
        ASSERT_NO_THROW(matrix5x4First.operator+(matrix5x4Third));
        EXPECT_EQ(matrix5x4First.operator+(matrix5x4Second), matrix5x4Third);
        EXPECT_FALSE(matrix5x4First.operator+(matrix5x4Third) == matrix5x4Third);
        EXPECT_ANY_THROW(matrix5x4First.operator+(matrix2x2First));
        
        ASSERT_NO_THROW(matrix5x6First.operator+(matrix5x6Second));
        ASSERT_NO_THROW(matrix5x6First.operator+(matrix5x6Third));
        EXPECT_EQ(matrix5x6First.operator+(matrix5x6Second), matrix5x6Third);
        EXPECT_FALSE(matrix5x6First.operator+(matrix5x6Third) == matrix5x6Third);
        EXPECT_ANY_THROW(matrix5x6First.operator+(matrix5x4First));
        
    }

    TEST_F(TestingMatrix, MultiplyMatrix){
        Matrix matrix2x2First = getMatrixSize2x2();
        Matrix matrix2x2Second = getMatrixSize2x2();
        Matrix matrix2x2Third = getMatrixSize2x2();
        
        Matrix matrix3x3First = getMatrixSize3x3();
        Matrix matrix3x3Second = getMatrixSize3x3();
        Matrix matrix3x3Third = getMatrixSize3x3();
        
        Matrix matrix5x6First = getMatrixSize5x6();
        Matrix matrix5x6Second = getMatrixSize5x6();
        Matrix matrix5x6Third = getMatrixSize5x6();
        
        //Vytvoříme si matice
        ASSERT_TRUE(matrix2x2First.set(std::vector<std::vector<double>> {{1, 2},{-2, -1.5}}));
        ASSERT_TRUE(matrix2x2Second.set(std::vector<std::vector<double>> {{1, 2},{1, 2}}));
        ASSERT_TRUE(matrix2x2Third.set(std::vector<std::vector<double>> {{3, 6},{-3.5, -7}}));
        
        ASSERT_TRUE(matrix3x3First.set(std::vector<std::vector<double>> {{1, 2, 3},{1, 2, 3},{1, 2, 3}}));
        ASSERT_TRUE(matrix3x3Second.set(std::vector<std::vector<double>> {{-1, -2, -3},{3, 2, 1},{0, 0, 0}}));
        ASSERT_TRUE(matrix3x3Third.set(std::vector<std::vector<double>> {{5, 2, -1},{5, 2, -1},{5, 2, -1}}));
        
        ASSERT_TRUE(matrix5x6First.set(std::vector<std::vector<double>> {{-1, -2.5, -3, -4.5, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6}}));
        ASSERT_TRUE(matrix5x6Second.set(std::vector<std::vector<double>> {{0, 0, 0, 0, 0, 0},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6}}));
        ASSERT_TRUE(matrix5x6Third.set(std::vector<std::vector<double>> {{-1, -2.5, -3, -4.5, 5, 6},{2, 4, 6, 8, 10, 12},{2, 4, 6, 8, 10, 12},{2, 4, 6, 8, 10, 12},{2, 4, 6, 8, 10, 12}}));
        
        //Otestujeme požadovanou funkcionalitu
        ASSERT_NO_THROW(matrix2x2First.operator*(matrix2x2Second));
        ASSERT_NO_THROW(matrix2x2First.operator*(matrix2x2Third));
        EXPECT_EQ(matrix2x2First.operator*(matrix2x2Second), matrix2x2Third);
        EXPECT_FALSE(matrix2x2First.operator*(matrix2x2Third) == matrix2x2Third);
        EXPECT_ANY_THROW(matrix2x2First.operator*(matrix3x3First));
        
        ASSERT_NO_THROW(matrix3x3First.operator*(matrix3x3Second));
        ASSERT_NO_THROW(matrix3x3First.operator*(matrix3x3Third));
        EXPECT_EQ(matrix3x3First.operator*(matrix3x3Second), matrix3x3Third);
        EXPECT_FALSE(matrix3x3First.operator*(matrix3x3Third) == matrix3x3Third);
        EXPECT_ANY_THROW(matrix3x3First.operator*(matrix2x2First));
        
        EXPECT_ANY_THROW(matrix5x6First.operator*(matrix5x6First));
        EXPECT_ANY_THROW(matrix5x6First.operator*(matrix5x6Second));
        EXPECT_ANY_THROW(matrix5x6First.operator*(matrix5x6Third));
        EXPECT_ANY_THROW(matrix5x6First.operator*(matrix2x2Second));
    }
    
    TEST_F(TestingMatrix, DotMultiplyMatrix){
        Matrix matrix2x2First = getMatrixSize2x2();
        Matrix matrix2x2Second = getMatrixSize2x2();
        Matrix matrix2x2Third = getMatrixSize2x2();
        Matrix matrix2x2Fourth = getMatrixSize2x2();
        
        Matrix matrix5x4First = getMatrixSize5x4();
        Matrix matrix5x4Second = getMatrixSize5x4();
        Matrix matrix5x4Third = getMatrixSize5x4();
        Matrix matrix5x4Fourth = getMatrixSize5x4();
        
        Matrix matrix5x6First = getMatrixSize5x6();
        Matrix matrix5x6Second = getMatrixSize5x6();
        Matrix matrix5x6Third = getMatrixSize5x6();
        Matrix matrix5x6Fourth = getMatrixSize5x6();
        
        //Vytvoříme si matice
        ASSERT_TRUE(matrix2x2First.set(std::vector<std::vector<double>> {{1, 2},{-2, -1.5}}));
        ASSERT_TRUE(matrix2x2Second.set(std::vector<std::vector<double>> {{2, 4},{-4, -3}}));
        ASSERT_TRUE(matrix2x2Third.set(std::vector<std::vector<double>> {{-5, -10},{10, 7.5}}));
        ASSERT_TRUE(matrix2x2Fourth.set(std::vector<std::vector<double>> {{0, 0},{0, 0}}));
        
        ASSERT_TRUE(matrix5x4First.set(std::vector<std::vector<double>> {{-1.5, 2, 3, 0},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4}}));
        ASSERT_TRUE(matrix5x4Second.set(std::vector<std::vector<double>> {{-3, 4, 6, 0},{2, 4, 6, 8},{2, 4, 6, 8},{2, 4, 6, 8},{2, 4, 6, 8}}));
        ASSERT_TRUE(matrix5x4Third.set(std::vector<std::vector<double>> {{7.5, -10, -15, 0},{-5, -10, -15, -20},{-5, -10, -15, -20},{-5, -10, -15, -20},{-5, -10, -15, -20}}));
        ASSERT_TRUE(matrix5x4Fourth.set(std::vector<std::vector<double>> {{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}}));
        
        ASSERT_TRUE(matrix5x6First.set(std::vector<std::vector<double>> {{-0, -4, -2, -1, 2.5, 3},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6}}));
        ASSERT_TRUE(matrix5x6Second.set(std::vector<std::vector<double>> {{0, -8, -4, -2, 5, 6},{2, 4, 6, 8, 10, 12},{2, 4, 6, 8, 10, 12},{2, 4, 6, 8, 10, 12},{2, 4, 6, 8, 10, 12}}));
        ASSERT_TRUE(matrix5x6Third.set(std::vector<std::vector<double>> {{0, 20, 10, 5, -12.5, -15},{-5, -10, -15, -20, -25, -30},{-5, -10, -15, -20, -25, -30},{-5, -10, -15, -20, -25, -30},{-5, -10, -15, -20, -25, -30}}));
        ASSERT_TRUE(matrix5x6Fourth.set(std::vector<std::vector<double>> {{0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0}}));
        
        //Otestujeme požadovanou funkcionalitu
        ASSERT_NO_THROW(matrix2x2First.operator*(2));
        ASSERT_NO_THROW(matrix2x2First.operator*(-5));
        ASSERT_NO_THROW(matrix2x2First.operator*(0));
        EXPECT_EQ(matrix2x2First.operator*(2), matrix2x2Second);
        EXPECT_EQ(matrix2x2First.operator*(-5), matrix2x2Third);
        EXPECT_EQ(matrix2x2First.operator*(0), matrix2x2Fourth);
        EXPECT_FALSE(matrix2x2First.operator*(100) == matrix2x2Third);
        
        ASSERT_NO_THROW(matrix5x4First.operator*(2));
        ASSERT_NO_THROW(matrix5x4First.operator*(-5));
        ASSERT_NO_THROW(matrix5x4First.operator*(0));
        EXPECT_EQ(matrix5x4First.operator*(2), matrix5x4Second);
        EXPECT_EQ(matrix5x4First.operator*(-5), matrix5x4Third);
        EXPECT_EQ(matrix5x4First.operator*(0), matrix5x4Fourth);
        EXPECT_FALSE(matrix5x4First.operator*(100) == matrix5x4Third);
        
        ASSERT_NO_THROW(matrix5x6First.operator*(2));
        ASSERT_NO_THROW(matrix5x6First.operator*(-5));
        ASSERT_NO_THROW(matrix5x6First.operator*(0));
        EXPECT_EQ(matrix5x6First.operator*(2), matrix5x6Second);
        EXPECT_EQ(matrix5x6First.operator*(-5), matrix5x6Third);
        EXPECT_EQ(matrix5x6First.operator*(0), matrix5x6Fourth);
        EXPECT_FALSE(matrix5x6First.operator*(100) == matrix5x6Third);
    }

    TEST_F(TestingMatrix, SolveEquation){
        Matrix matrix1x1First = getMatrixSize1x1();
        std::vector<double> vectorFor1x1Correct = {2};
        std::vector<double> vectorFor1x1Uncorrect = {0};
        
        Matrix matrix2x2First = getMatrixSize2x2();
        Matrix matrix2x2Second = getMatrixSize2x2();
        Matrix matrix2x2Third = getMatrixSize2x2();
        std::vector<double> vectorFor2x2Correct = {1, 1};
        std::vector<double> vectorFor2x2Uncorrect = {-1, 1};
        
        Matrix matrix3x3First = getMatrixSize3x3();
        std::vector<double> vectorFor3x3Correct = {-5, 11.5, -3.5};
        std::vector<double> vectorFor3x3Uncorrect = {0, 1000, 0.1};
        
        Matrix matrix4x4First = getMatrixSize4x4();
        std::vector<double> vectorFor4x4Correct = {-1, 1, 1, -1};
        std::vector<double> vectorFor4x4Uncorrect = {0, 1000, 0.1, 8};
        
        Matrix matrix5x6First = getMatrixSize5x6();
        Matrix matrix5x4First = getMatrixSize5x4();
        Matrix matrix2x3First = getMatrixSize2x3();
        
        //Vytvoříme si matice
        ASSERT_TRUE(matrix1x1First.set(std::vector<std::vector<double>> {{1}}));
        ASSERT_TRUE(matrix2x2First.set(std::vector<std::vector<double>> {{1, 2},{2, 3}}));
        ASSERT_TRUE(matrix2x2Second.set(std::vector<std::vector<double>> {{1, 2},{1, 2}}));
        ASSERT_TRUE(matrix3x3First.set(std::vector<std::vector<double>> {{1, 2, 4},{5, 3, 1},{1, 1, 1}}));
        ASSERT_TRUE(matrix4x4First.set(std::vector<std::vector<double>> {{1, 1, 2, 2},{1, 3, 1, 3},{1, 1, 1, 1},{1, 2, 3, 1}}));
        ASSERT_TRUE(matrix5x6First.set(std::vector<std::vector<double>> {{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6},{1, 2, 3, 4, 5, 6}}));
        ASSERT_TRUE(matrix5x4First.set(std::vector<std::vector<double>> {{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4},{1, 2, 3, 4}}));
        
        //Otestujeme požadovanou funkcionalitu
        ASSERT_NO_THROW(matrix1x1First.solveEquation(std::vector<double> {2}));
        EXPECT_ANY_THROW(matrix1x1First.solveEquation(std::vector<double> {4, 6, 3}));
        EXPECT_TRUE(matrix1x1First.solveEquation(std::vector<double> {2}) == vectorFor1x1Correct);
        EXPECT_FALSE(matrix1x1First.solveEquation(std::vector<double> {2}) == vectorFor1x1Uncorrect);
        
        ASSERT_NO_THROW(matrix2x2First.solveEquation(std::vector<double> {3, 5}));
        EXPECT_ANY_THROW(matrix2x2First.solveEquation(std::vector<double> {4, 6, 3}));
        EXPECT_TRUE(matrix2x2First.solveEquation(std::vector<double> {3, 5}) == vectorFor2x2Correct);
        EXPECT_FALSE(matrix2x2First.solveEquation(std::vector<double> {3, 5}) == vectorFor2x2Uncorrect);
        EXPECT_ANY_THROW(matrix2x2Second.solveEquation(std::vector<double> {1, 2}));
        EXPECT_FALSE(matrix2x2Third.set(std::vector<std::vector<double>> {{1, 2, 3},{2, 3}}));
        
        ASSERT_NO_THROW(matrix3x3First.solveEquation(std::vector<double> {4, 6, 3}));
        EXPECT_ANY_THROW(matrix3x3First.solveEquation(std::vector<double> {4, 6}));
        EXPECT_TRUE(matrix3x3First.solveEquation(std::vector<double> {4, 6, 3}) == vectorFor3x3Correct);
        EXPECT_FALSE(matrix3x3First.solveEquation(std::vector<double> {4, 6, 3}) == vectorFor3x3Uncorrect);
        
        ASSERT_NO_THROW(matrix4x4First.solveEquation(std::vector<double> {0, 0, 0, 3}));
        EXPECT_ANY_THROW(matrix4x4First.solveEquation(std::vector<double> {4, 6}));
        EXPECT_TRUE(matrix4x4First.solveEquation(std::vector<double> {0, 0, 0, 3}) == vectorFor4x4Correct);
        EXPECT_FALSE(matrix4x4First.solveEquation(std::vector<double> {0, 0, 0, 3}) == vectorFor4x4Uncorrect);
        
        EXPECT_ANY_THROW(matrix5x6First.solveEquation(std::vector<double> {4, 6, 3, 0, 0}));
        EXPECT_ANY_THROW(matrix5x4First.solveEquation(std::vector<double> {4, 6, 3, 0, 0}));
        EXPECT_ANY_THROW(matrix2x3First.solveEquation(std::vector<double> {4, 6, 3}));
    }
}

/*** Konec souboru white_box_tests.cpp ***/
