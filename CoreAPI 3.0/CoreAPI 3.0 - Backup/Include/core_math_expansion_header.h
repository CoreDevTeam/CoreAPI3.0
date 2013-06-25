#ifndef CORE_MATH_EXPANISION_HEADER_H_INCLUDED
#define CORE_MATH_EXPANISION_HEADER_H_INCLUDED

namespace math {

class Math {

public :

     template <class Typ>
     static Typ add(Typ a, Typ b);

     template <class Typ>
     static Typ sub(Typ a, Typ b) {
          return a-b;
     }

     template <class Typ>
     static Typ div(Typ a, Typ b) {
          return a/b;
     }

     template <class Typ>
     static Typ mul(Typ a, Typ b) {
          return a*b;
     }

     template <class Typ>
     static Typ square(Typ a) {
          return a*a;
     }

     template <class Typ>
     static Typ fraction(Typ _1a,Typ _2a) {
          return (_1a/_2a);
     }

     template <class Typ>
     static Typ fractionadd(Typ _1a,Typ _2a,Typ _1b,Typ _2b) {
          return (_1a/_2a)+(_1b/_2b);
     }

     template <class Typ>
     static Typ fractionsub(Typ _1a,Typ _2a,Typ _1b,Typ _2b) {
          return (_1a/_2a)-(_1b/_2b);
     }

     template <class Typ>
     static Typ fractionmul(Typ _1a,Typ _2a,Typ _1b,Typ _2b) {
          return (_1a/_2a)*(_1b/_2b);
     }

     template <class Typ>
     static Typ fractiondiv(Typ _1a,Typ _2a,Typ _1b,Typ _2b) {
          return (_1a/_2a)/(_1b/_2b);
     }

// How to use : math::Math::add<A TYPE YOU WANT >(VAR 1, VAR 2 ...)
};//class Math ends

}//namespace math ends

#endif // CORE_MATH_EXPANISION_HEADER_H_INCLUDED
