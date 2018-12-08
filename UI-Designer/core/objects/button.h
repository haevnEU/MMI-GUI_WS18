#ifndef BUTTON_H
#define BUTTON_H

#include "IBaseElement.h"
#include <QPushButton>

namespace core {
    namespace objects {

        class Button : public IBaseElement, public QPushButton
        {
        public:
            Button();

        private:
            void onlyUseToCreateAnAbstractClass(){}
        };
    } // namespace objects
} // namespace core

#endif // BUTTON_H
