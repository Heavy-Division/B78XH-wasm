#pragma once

class CheckListDimensions {
    public:
        static constexpr float TOTAL_LINE_HEIGHT = 70;
        static constexpr float TOTAL_WIDTH = 700;  // should match half MFD width
        static constexpr float MARGIN = 8;
        static constexpr float BORDER_WIDTH = 5;
        static constexpr float INNER_START = MARGIN + BORDER_WIDTH / 2;
        static constexpr float INNER_HEIGHT = TOTAL_LINE_HEIGHT - 2 * INNER_START;
        static constexpr float ONE_FORTH_INNER_HEIGHT = INNER_HEIGHT / 4;
        static constexpr float INNER_Y_END = TOTAL_LINE_HEIGHT - INNER_START;
};
