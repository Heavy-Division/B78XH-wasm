#pragma once

class CheckListDimensions {
    public:
        static constexpr float TOTAL_HEIGHT = 50;
        static constexpr float TOTAL_WIDTH = 700;  // should match half MFD width
        static constexpr float MARGIN = 5;
        static constexpr float INNER_HEIGHT = TOTAL_HEIGHT - 2 * MARGIN;
        static constexpr float ONE_FORTH_INNER_HEIGHT = INNER_HEIGHT / 4;
        static constexpr float INNER_Y_END = TOTAL_HEIGHT - MARGIN;

};
