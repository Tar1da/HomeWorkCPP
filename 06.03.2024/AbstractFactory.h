#pragma once
#include <iostream>
using namespace std;

class Pieces;
class Dough;
class Cookie;

// Abstract classes

class CookieFactory {
public:
    virtual Pieces* createPieces() = 0;
    virtual Dough* createDough() = 0;
    virtual Cookie* createCookie() = 0;
    virtual string nameFactory() = 0;
};

class Pieces {
public:
    virtual string getInfo() = 0;
};

class Dough {
public:
    virtual string getInfo() = 0;
};

// Pieces

class CocosPieces : public Pieces {
public:
    string getInfo()
    {
        return "CocosPieces";
    }
};

class ChocoPieces : public Pieces {
public:
    string getInfo()
    {
        return "ChocoPieces";
    }
};

// Dough

class CocosDough : public Dough {
public:
    string getInfo()
    {
        return "CocosDough";
    }
};

class ChocoDough : public Dough {
public:
    string getInfo()
    {
        return "ChocoDough";
    }
};

// Cookie

class Cookie {
    string dough;
    string pieces;
public:
    Cookie(string dough, string pieces)
    {
        this->dough = dough;
        this->pieces = pieces;
    }
    void getinfo()
    {
        cout << "Cookie\n" << "Dough: " << dough << endl
            << "Pieces: " << pieces << endl << endl;
    }
};

// Factories

class CocosCookieFactory : public CookieFactory {
public:
    Dough* createDough()
    {
        Dough* dough = new CocosDough;
        return dough;
    }

    Pieces* createPieces() 
    {
        Pieces* pieces = new CocosPieces;
        return pieces;
    }

    Cookie* createCookie()
    {
        Cookie* cookie = new Cookie(createDough()->getInfo(), createPieces()->getInfo());
        return cookie;
    }
    string nameFactory()
    {
        return "CocosCookieFactory";
    }
};

class ChocoCookieFactory : public CookieFactory {
public:
    Dough* createDough()
    {
        Dough* dough = new ChocoDough;
        return dough;
    }

    Pieces* createPieces()
    {
        Pieces* pieces = new ChocoPieces;
        return pieces;
    }

    Cookie* createCookie()
    {
        Cookie* cookie = new Cookie(createDough()->getInfo(), createPieces()->getInfo());
        return cookie;
    }
    string nameFactory()
    {
        return "ChocoCookieFactory";
    }
};


// Client

class Client {
    CookieFactory* factory;
public:
    Client(CookieFactory* factory)
    {
        this->factory = factory;
    }
    Cookie* getProduct()
    {
        return factory->createCookie();
    }
    CookieFactory* getFactory()
    {
        return factory;
    }
};