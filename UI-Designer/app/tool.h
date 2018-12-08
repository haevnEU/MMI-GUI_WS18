#ifndef ZEICHEN_PRORGAMM_APP_TOOL_H
#define ZEICHEN_PRORGAMM_APP_TOOL_H

namespace app {

    /**
     * @file tool.h
     * @brief This header file will contain the enumeration for every tool
     *
     * @author Nils Mielwski (nils.milewski@stud.hs-ruhrwest.de)
     *
     * @version 1.0
     * @date 12/02/2018
     */
    enum Tool{
        /// This enabled rectangle operation
        RECTANGLE,
        /// This enabled square operation
        SQUARE,
        /// This enabled circle operation
        CIRCLE,
        /// This enabled delete operation
        DELETE,
        /// This disable all operation
        NO_SELECTION,
        /// This enabled button operation
        BUTTON
    };
}

#endif // ZEICHEN_PRORGAMM_APP_TOOL_H
