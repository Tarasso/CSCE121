#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "tinyxml2/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

struct Book
{
  string title;
  string author;
  int year;
};

struct Product
{
  string name;
  int price;
};

int hashComp(pair<string,int> one, pair<string, int> two)
{
  return one.second<two.second;
}

int compare(Product one, Product two)
{
  return one.price<two.price;
}

void readBooks()
{
  vector<Book> books;
  unordered_map<string,int> hash;
  XMLDocument doc;
	doc.LoadFile( "books.xml" );
  XMLElement* book = doc.FirstChildElement("BOOKS")->FirstChildElement("Book");
  while(book!= nullptr)
  {
    const char* title = book->FirstChildElement("title")->GetText();
    const char* author = book->FirstChildElement("author")->GetText();
    const char* year = book->FirstChildElement("year")->GetText();
    Book tempBook;
    tempBook.title = title;
    tempBook.author = author;
    tempBook.year = atoi(year);
    books.push_back(tempBook);
    if(hash.find(author)==hash.end())
      hash[author] = 1;
    else
      hash[author]++;
    book = book->NextSiblingElement();
  }
  for(int i = 0; i < books.size(); i++)
  {
    cout << books[i].title << endl;
    cout << books[i].author << endl;
    cout << books[i].year << endl;
    cout << endl;
  }
  vector<pair<string,int> > pairs(hash.begin(),hash.end());
  sort(pairs.begin(),pairs.end(),hashComp);
  cout << "Sorted by most books by author" << endl;
  for(int i = 0; i < pairs.size(); i++) //change num???
  {
    cout << pairs[i].second << " " << pairs[i].first<< endl;
  }
}

void readProducts()
{
  vector<Product> products;
  XMLDocument doc;
	doc.LoadFile( "products.xml" );
  XMLElement* product = doc.FirstChildElement("Products")->FirstChildElement("Product");
  while(product!= nullptr)
  {
    const char* name = product->FirstChildElement("Name")->GetText();
    const char* price = product->FirstChildElement("Price")->GetText();
    Product tempProduct;
    tempProduct.name = name;
    tempProduct.price = atoi(price);
    products.push_back(tempProduct);
    product = product->NextSiblingElement();
  }
  sort(products.begin(),products.end(),compare);
  for(int i = 0; i < products.size(); i++)
  {
    cout << products[i].name << " $" << products[i].price << endl;
  }
}

int main()
{
  cout << "Books:" << endl;
  readBooks();
  cout << endl << "Products by price:" << endl;
  readProducts();
}
