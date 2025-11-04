class FizzBuzz {
private:
    int n;
    pthread_mutex_t mtx;
    pthread_cond_t cv;
public:
    int cnt;
    FizzBuzz(int n) {
        this->n = n;
        cnt = 1;
        pthread_mutex_init(&mtx, NULL);
        pthread_cond_init(&cv, NULL);
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true) {
            pthread_mutex_lock(&mtx);
                while((cnt <= n) && ((cnt % 3 != 0) || (cnt % 5 == 0))) {
                    pthread_cond_wait(&cv, &mtx);
                }
                if(cnt > n) {
                    pthread_cond_broadcast(&cv);
                    pthread_mutex_unlock(&mtx);
                    return;
                }
                printFizz();
                cnt++;
            pthread_cond_broadcast(&cv);
            pthread_mutex_unlock(&mtx);
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true) {
            pthread_mutex_lock(&mtx) ;
                while((cnt <= n) && ((cnt % 5 != 0) || (cnt % 3 == 0)))
                    pthread_cond_wait(&cv, &mtx);
                if(cnt > n){
                    pthread_cond_broadcast(&cv);
                    pthread_mutex_unlock(&mtx);
                    return;
                }
                printBuzz();
                cnt++;
            pthread_cond_broadcast(&cv);
            pthread_mutex_unlock(&mtx);
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true) {
            pthread_mutex_lock(&mtx);
                while((cnt <= n) && ((cnt % 3 != 0) || (cnt % 5 != 0)))
                    pthread_cond_wait(&cv, &mtx);
                if(cnt > n) {
                    pthread_cond_broadcast(&cv);
                    pthread_mutex_unlock(&mtx);
                    return;
                }
                printFizzBuzz();
                cnt++;
            pthread_cond_broadcast(&cv);
            pthread_mutex_unlock(&mtx);
        }
    }
    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true) {
            pthread_mutex_lock(&mtx);
                while((cnt <= n) && ((cnt % 3 == 0) || (cnt % 5 == 0)))
                    pthread_cond_wait(&cv, &mtx);
                if(cnt > n) {
                    pthread_cond_broadcast(&cv);
                    pthread_mutex_unlock(&mtx);
                    return;
                }
                printNumber(cnt);
                cnt++;
            pthread_cond_broadcast(&cv);
            pthread_mutex_unlock(&mtx);
        }
    }
};