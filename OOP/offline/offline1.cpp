#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
class Fraction
{
private:
    int numerator;
    int denominator;

public:
    void simplify()
    {
        int Gcd = gcd(abs(numerator), abs(denominator));
        numerator /= Gcd;
        denominator /= Gcd;
    }
    Fraction()
    {
        numerator = 0;
        denominator = 1;
    }
    Fraction(int n)
    {
        numerator = n;
        denominator = 1;
    }
    Fraction(int n, int d)
    {
        if (d != 0)
        {
            numerator = n;
            denominator = d;
            simplify();
        }
        else
        {
            cout << "invalid";
            numerator = n;
            denominator = 1;
        }
    }
    void print()
    {
        cout << numerator << '/' << denominator << endl;
    }
    Fraction add(Fraction &f)
    {
        int n = numerator * f.denominator + f.numerator * denominator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }
    Fraction add(int x)
    {
        int n = numerator + denominator * x;

        return Fraction(n, denominator);
    }
    Fraction sub(Fraction &f)
    {
        int n = numerator * f.denominator - f.numerator * denominator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }
    Fraction sub(int x)
    {
        int n = numerator - denominator * x;

        return Fraction(n, denominator);
    }
    Fraction mul(Fraction &f)
    {
        int n = numerator * f.numerator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }
    Fraction mul(int x)
    {
        int n = numerator * x;

        return Fraction(n, denominator);
    }
    Fraction div(Fraction &f)
    {
        int n = numerator * f.denominator;
        int d = denominator * f.numerator;
        return Fraction(n, d);
    }
    Fraction div(int x)
    {
        if (x != 0)
        {
            int d = denominator * x;

            return Fraction(numerator, d);
        }
        else
        {
            cout << "cannot divide by 0" << endl;
            return *this;
        }
    }
    int getNumerator()
    {
        return numerator;
    }
    int getDenominator()
    {
        return denominator;
    }
    double realVal()
    {
        return 1.0 * numerator / denominator;
    }
};
class FractionCollection
{
    Fraction *fractions;
    int maxlength;
    int length;

public:
    FractionCollection()
    {
        length = 0;
        maxlength = 10;

        fractions = new Fraction[10];
    }
    FractionCollection(int n)
    {
        length = 0;

        maxlength = n;
        fractions = new Fraction[n];
    }

    ~FractionCollection()
    {
        delete[] fractions;
    }
    void insert(Fraction f)
    {
        if (length >= maxlength)
        {
            int newCapacity = maxlength * 2;
            Fraction *newFractions = new Fraction[newCapacity];
            for (int i = 0; i < length; i++)
            {
                newFractions[i] = fractions[i];
            }
            delete[] fractions;
            fractions = newFractions;
            maxlength = newCapacity;
        }

        fractions[length] = f;
        length++;
    }
    void insert(int pos, Fraction f)
    {

        if (pos > length)
        {
            cout << "can't add element";
        }
        else
        {
            for (int i = length; i > pos; i--)
            {
                fractions[i] = fractions[i - 1];
            }
            fractions[pos] = f;
            length++;
        }
    }
    void remove()
    {

        length--;
    }
    void remove(int pos)
    {
        for (int i = pos; i < length; i++)
        {
            fractions[i] = fractions[i + 1];
        }
        length--;
    }
    void remove(Fraction f)
    {
        int pos = -1;
        for (int i = 0; i < length; i++)
        {
            if (fractions[i].getNumerator() == f.getNumerator() &&
                fractions[i].getDenominator() == f.getDenominator())
            {
                pos = i;
            }
        }
        if (pos == -1)
        {
            cout << "cant find fraction";
        }
        else
        {
            remove(pos);
        }
    }
    Fraction getmax()
    {
        Fraction mx = fractions[0];
        for (int i = 1; i < length; i++)
        {
            if (mx.realVal() < fractions[i].realVal())
            {
                mx = fractions[i];
            }
        }
        return mx;
    }
    Fraction getmin()
    {
        Fraction mn = fractions[0];
        for (int i = 1; i < length; i++)
        {
            if (mn.realVal() > fractions[i].realVal())
            {
                mn = fractions[i];
            }
        }
        return mn;
    }
    Fraction add(int start, int end)
    {
        Fraction sum = fractions[start];
        for (int i = start + 1; i <= end; i++)
        {
            sum = sum.add(fractions[i]);
        }
        return sum;
    }
    Fraction mul(int start, int end)
    {
        Fraction ml = fractions[start];
        for (int i = start + 1; i <= end; i++)
        {
            ml = ml.mul(fractions[i]);
        }
        return ml;
    }
    Fraction sub(int pos1, int pos2)
    {
        Fraction sb = fractions[pos1];
        sb = sb.sub(fractions[pos2]);
        return sb;
    }
    Fraction div(int pos1, int pos2)
    {
        Fraction dv = fractions[pos1];
        dv = dv.div(fractions[pos2]);
        return dv;
    }
    void print()
    {
        for (int i = 0; i < length; i++)
        {
            cout << "Fraction " << i << " :";
            fractions[i].print();
        }
        cout << "MAX : ";
        getmax().print();
        cout << "MIN : ";
        getmin().print();
        cout << "Summation : ";
        add(0, length - 1).print();
        cout << "Multiplication : ";
        mul(0, length - 1).print();
        cout << endl
             << endl;
    }
};
int main()
{
    // create Fraction with numerator, denominator
    Fraction a(5, 2), b(7, 2), c(9, 2), d(28, 5);
    cout << "Fraction" << endl;
    cout << "-------------------------------" << endl;
    cout << "A: ";
    cout << "A: ";
    a.print();
    cout << "B: ";
    b.print();
    cout << endl;
    cout << "Add(a,b): ";

    a.add(b).print();
    cout << "Add(a,2): ";
    a.add(2).print();
    cout << "Sub(a,b) ";

    a.sub(b).print();
    cout << "Sub(a,2) ";
    a.sub(2).print();

    cout << "Mul(a,b): ";
    a.mul(b).print();
    cout << "Mul(a,2): ";
    a.mul(2).print();

    cout << "Div(a,b): ";
    a.div(b).print();
    cout << "Div(a,2): ";
    a.div(2).print();
    cout << "Div(a,0): ";
    a.div(0).print();

    Fraction e, f(5), g(10);
    FractionCollection fc(10);
    fc.insert(a);
    fc.insert(b);
    fc.insert(c);
    fc.print();
    cout << "Sub(Pos0, Pos1): ";
    fc.sub(0, 1).print();
    cout << "Div(Pos0, Pos1): ";
    fc.div(0, 1).print(); // divides the fraction at pos0 by the fraction at pos1
    fc.remove(1);         // removed 'b'
    fc.print();
    fc.remove(a);
    fc.print();
    fc.insert(d);
    fc.insert(0, e); // insert at pos0
    fc.insert(f);
    fc.insert(g);
    fc.print();
    fc.remove(); // removed the last fraction
    fc.print();  // notice the output
    return 0;
}