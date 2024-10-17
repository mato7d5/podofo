/**
 * SPDX-FileCopyrightText: (C) 2021 Francesco Pretto <ceztko@gmail.com>
 * SPDX-License-Identifier: LGPL-2.0-or-later
 * SPDX-License-Identifier: MPL-2.0
 */

#ifndef PDF_TEXT_STATE_H
#define PDF_TEXT_STATE_H

#include "PdfDeclarations.h"

namespace PoDoFo
{
    class PdfFont;

    // TODO: Add missing properties ISO 32000-1:2008 "9.3 Text State Parameters and Operators"
    struct PODOFO_API PdfTextState final
    {
        /** Split text into individual lines, using the current font state and width.
         *
         *  \param str the text which should be split
         *  \param width width of the text area
         *  \param skipTrailingSpaces whether trailing whitespaces should be skipped, so that next line doesn't start with whitespace
         */
        std::vector<std::string> SplitTextAsLines(const std::string_view& str, double width, bool skipTrailingSpaces = false) const;

        const PdfFont* Font = nullptr;
        double FontSize = -1;
        double FontScale = 1;
        double CharSpacing = 0;
        double WordSpacing = 0;
        PdfTextRenderingMode RenderingMode = PdfTextRenderingMode::Fill;
    };
}

#endif // PDF_TEXT_STATE_H
