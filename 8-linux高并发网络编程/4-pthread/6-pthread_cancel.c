#include <pthread.h>
#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;

void *test_cannel(void *arg)
{
    //pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);
    while (true)
    {
        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
        cout << "1" << endl;
        cout << "2" << endl;
        cout << "3" << endl;
        cout << "4" << endl;
        cout << "5" << endl;
        cout << "6" << endl;
        cout << "7" << endl;
        sleep(1);
        pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
        pthread_testcancel();
    }
}

void *test_no_cannel(void *arg)
{
    // pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,NULL);
    while (true)
    {
        cout << "1" << endl;
        cout << "2" << endl;
        cout << "3" << endl;
        cout << "4" << endl;
        cout << "5" << endl;
        cout << "6" << endl;
        cout << "7" << endl;
        sleep(1);
    }
}

int main()
{

    pthread_t p1;
    pthread_create(&p1, NULL, test_cannel, NULL);
    sleep(1);
    pthread_cancel(p1);
    pthread_join(p1, NULL);

    return 0;
}
