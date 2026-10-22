#include <time>

class Bill{
    private:
        int billID;
        std::time_t creationDate;
        double total;
    public:
        double countTotal();
};