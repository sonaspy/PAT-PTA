// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Primes
{
public:
    vector<uint64_t> prime_numbers;
    Primes()
    {
        prime_generate();
    }

private:
    inline bool __isprime(uint64_t num)
    {
        if (num < 2 || (num != 2 && num % 2 == 0))
            return false;
        uint64_t s = sqrt(num);
        for (uint64_t i = 3; i <= s; i += 2)
            if (num % i == 0)
                return false;
        return true;
    }
    void prime_generate()
    {
        int n = 2;
        for (uint64_t i = 0; i < 10000; i++)
        {
            while (!__isprime(n))
                n++;
            this->prime_numbers.push_back(n);
            n++;
        }
    }
} global_primes;

class RSA
{
public:
    RSA()
    {
        __perpration();
    }

    uint64_t classify(uint64_t m)
    {
        uint64_t Cypher = uint64_t(pow(m, this->__public_key)) % __n;
        return Cypher;
    }

    uint64_t declassify(uint64_t Cypher)
    {
        uint64_t m = uint64_t(pow(Cypher, this->__private_key)) % __n;
        return m;
    }

private:
    uint64_t __public_key, __private_key, __n, __Fn;
    vector<uint64_t> *prime_numbers;
    inline uint64_t __GCD(uint64_t m, uint64_t n)
    {
        uint64_t r;
        while (n > 0)
        {
            r = m % n;
            m = n;
            n = r;
        }
        return m;
    }

    void __perpration()
    {
        prime_numbers = &global_primes.prime_numbers;
        uint64_t p, q, Fn, pub_key, pri_key, bound, n, c;

        // p = this->prime_numbers[rand() % 3];
        // while ((q = this->prime_numbers[rand() % 3]) == p)
        //     ;
        p = 3, q = 11;
        Fn = (p - 1) * (q - 1);
        n = p * q;

        bound = lower_bound(this->prime_numbers->begin(), this->prime_numbers->end(), Fn) - this->prime_numbers->begin();
        c = 0;
        while (c < bound && __GCD(Fn, pub_key = (*(this->prime_numbers))[c++]) != 1)
            ;

        pri_key = 1;

        while ((((++pri_key * pub_key) % Fn != 1)) || pri_key == pub_key)
            ;

        cout << "p: " << p << "   q: " << q << endl
             << "Fn: " << Fn << " -> "
             << " n: " << n << endl
             << "Public Key: " << pub_key << endl
             << "Private Key: " << pri_key << endl;
        cout << (pri_key * pub_key) % Fn << endl;

        this->__public_key = pub_key;
        this->__private_key = pri_key;
        this->__n = n;
        this->__Fn = Fn;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    srand(time(NULL));
    int n = 10, x = 10;
    RSA demo;
    bool valid = true;
    while (x--)
    {
        while (n--)
        {
            uint64_t m = rand() % 1000 + 1;
            uint64_t c = demo.classify(m);
            if (!(demo.declassify(c) == m))
                goto end;
        }
        n = 10;
    }

end:
    cout << (valid ? "Valid" : "Non-Valid") << endl;
    return 0;
}