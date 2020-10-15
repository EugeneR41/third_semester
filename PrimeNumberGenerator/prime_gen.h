class PrimeNumberGenerator {
    int start_pos;
 public:
    explicit PrimeNumberGenerator(int start) {
        if (start != 1)
            start_pos = start;
        else
            start_pos = start + 1;
    }

    int GetNextPrime() {
        bool prime_number = false;
        bool not_a_prime = false;

        while (!prime_number) {
            for (int i = 2; i < start_pos; i++) {
                if (start_pos % i == 0) {
                    not_a_prime = true;
                    break;
                }
            }
            if (not_a_prime) {
                not_a_prime = false;
                start_pos++;
            } else {
                prime_number = true;
            }
        }

        return start_pos++;
    }
};