/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
  ariel::Tree emptytree;
  ariel::Tree threetree; 
  ariel::Tree solutiontree; 
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  solutiontree.insert(50);
  solutiontree.insert(60);
  solutiontree.insert(10);
  solutiontree.insert(20);
  solutiontree.insert(9);
  solutiontree.insert(55);
  solutiontree.insert(65);
  solutiontree.insert(68);
  solutiontree.insert(24);
  solutiontree.insert(30);

  /* solutiontree visualization:
             50
           /    \
         10      60
         /\      /\
        9 20    55 65
           \        \
            24       68
             \
              30
  */

  badkan::TestCase tc("Binary tree");
  tc
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())

  .CHECK_EQUAL (solutiontree.contains(10), true)
  .CHECK_OK    (solutiontree.insert(3))
  .CHECK_OK    (solutiontree.remove(65))
  .CHECK_EQUAL (solutiontree.root(), 50)
  .CHECK_THROWS(solutiontree.remove(9))
  .CHECK_THROWS(solutiontree.insert(55))
  .CHECK_EQUAL (solutiontree.parent(60), 50)
  .CHECK_EQUAL (solutiontree.size() ,2)
  .CHECK_EQUAL (solutiontree.size() ,4)
  .CHECK_OK    (solutiontree.print())

  .print();
  
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
