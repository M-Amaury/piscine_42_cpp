#include <string>

#define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFO "I cannot believe adding extra bacon costs more money. You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more!"
#define WARNING "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month."
#define ERROR "This is unacceptable! I want to speak to the manager now."

class Harl {
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );

    public:
        Harl(void);
        ~Harl(void);
        void complain(std::string level);
        typedef struct s_level {
            std::string debugString;
            void (Harl::*f)(void);
        } t_levels;
};
