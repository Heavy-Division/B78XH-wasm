//    B78XH-wasm
//    Copyright (C) 2022  Heavy Division
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.


#include "CDULineRenderer.h"
#include "fmt/core.h"
#include "Tools.h"

CDULineRenderer::CDULineRenderer(NVGcontext*& context): context(context) {
}

auto CDULineRenderer::draw(CDULineType type, CDULineNumber lineNumber, CDULineAlign lineAlign,
                           std::vector<std::vector<std::string>>& content) -> void {
	this->lineType = type;
	this->lineNumber = lineNumber;
	this->lineAlign = lineAlign;
	this->prepareContent(content);
	this->calculateHorizontalOffset();
	this->drawComplexLine();
	this->clearData();
}

auto CDULineRenderer::drawComplexLine() -> void {
	const auto data = this->complexContentData;
	const auto dataSize = data.size();

	nvgSave(this->context);
	{
		nvgFillColor(this->context, Tools::Colors::white);
		nvgFontSize(this->context, this->fontSize);
		nvgTextAlign(this->context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);

		nvgTranslate(this->context, this->horizontalOffset, this->getVerticalOffset());
		{
			float lastBounds[4] = {0, 0, 0, 0};
			float nextBounds[4];
			float preSettableBounds[4];
			float endSettableBounds[4];

			int firstSettable = -1;
			int lastSettable = -1;

			for (int i = dataSize - 1; i >= 0; i--) {
				if (std::get<2>(data.at(i)) && firstSettable == -1) {
					firstSettable = i;
					lastSettable = i;
				}
				else if (std::get<2>(data.at(i)) && firstSettable != -1) {
					lastSettable = i;
				}
			}


			if (firstSettable != -1) {
				std::string preSettableText;
				std::string endSettableText;
				for (int i = dataSize - 1; i > firstSettable; i--) {
					preSettableText += std::get<0>(data.at(i));
				}

				for (int i = dataSize - 1; i >= lastSettable; i--) {
					endSettableText += std::get<0>(data.at(i));
				}

				nvgTextBounds(this->context, lastBounds[2], 0, preSettableText.c_str(), nullptr, preSettableBounds);
				nvgTextBounds(this->context, preSettableBounds[2], 0, endSettableText.c_str(), nullptr,
					endSettableBounds);

				nvgBeginPath(this->context);
				{
					/*
					 * How the fuck this works?? Why is there the loop??? Why this should even loop the data?? Why this should calculate the nextBounds???
					 * Is this a legacy code???
					 * TODO: Need to be checked
					 */
					/*
					for (int i = 0; i < dataSize; i++) {
						const std::string character = std::get<0>(data.at(i));
						nvgTextBounds(this->context, lastBounds[2], 0, character.c_str(), nullptr, nextBounds);
						nvgFillColor(this->context, Tools::Colors::cduButtonGray);
						nvgRect(this->context, preSettableBounds[0] + 5, -16,
								-(endSettableBounds[2] - endSettableBounds[0]) - 10, 28);
					}
					*/

					nvgFillColor(this->context, Tools::Colors::cduButtonGray);



					nvgRect(this->context, -(endSettableBounds[2] - endSettableBounds[0]) - 5.0f, -16,
						preSettableBounds[0] + 5.0f - (-(endSettableBounds[2] - endSettableBounds[0]) - 5.0f), 28);
				}
				nvgClosePath(this->context);
				nvgFill(this->context);

				
				constexpr float borderWidth = 3.0f;
				const float rightXPosition = preSettableBounds[0] + 5.0f;
				const float leftXPosition = -(endSettableBounds[2] - endSettableBounds[0]) - 5.0f;
				constexpr float topYPosition = -16.0f;
				constexpr float bottomYPosition = 12.0f;

				/*
				 * Settable borders
				 */

				/*
				 * Be aware:
				 * Borders do not have shape:
				 *  ________________
				 *  \              /
				 *   \____________/
				 *
				 * the shape is:
				 *   _______________
				 *  |              /
				 *  |_____________/
				 *
				 * this shape prevent background leak in corners
				 *
				 */
				{
					/*
					 * Top Border
					 * Be aware the rendering is reversed!! Because of backward rendering of text the preSettableBounds are actually bounds for right side
					 */
					nvgFillColor(this->context, Tools::Colors::cduSettableBorderTopGray);
					nvgBeginPath(this->context);
					{
						/*
						 * Begin
						 */
						nvgMoveTo(this->context, rightXPosition, topYPosition);
						/*
						 * Top line
						 */
						nvgLineTo(this->context, leftXPosition, topYPosition);
						/*
						 * Left line
						 */
						nvgLineTo(this->context, leftXPosition, topYPosition + borderWidth);
						/*
						 * Bottom line
						 */
						nvgLineTo(this->context, rightXPosition, topYPosition + borderWidth);
						/*
						 * Right line
						 */
						nvgLineTo(this->context, rightXPosition, topYPosition);
					}
					nvgClosePath(this->context);
					nvgFill(this->context);

					/*
					 * RIGHT
					 */
					nvgFillColor(this->context, Tools::Colors::cduSettableBorderRightGray);
					nvgBeginPath(this->context);
					{
						/*
						 * Begin
						 */
						nvgMoveTo(this->context, rightXPosition, topYPosition);
						/*
						 * Top line
						 */
						nvgLineTo(this->context, rightXPosition - borderWidth, topYPosition + borderWidth);
						/*
						 * Left line
						 */
						nvgLineTo(this->context, rightXPosition - borderWidth, bottomYPosition);
						/*
						 * Bottom line
						 */
						nvgLineTo(this->context, rightXPosition, bottomYPosition);
						/*
						 * Right line
						 */
						nvgLineTo(this->context, rightXPosition, topYPosition);
					}
					nvgClosePath(this->context);
					nvgFill(this->context);

					/*
					 * Bottom Border
					 * Be aware the rendering is reversed!! Because of backward rendering of text the preSettableBounds are actually bounds for right side
					 */
					nvgFillColor(this->context, Tools::Colors::cduSettableBorderBottomGray);
					nvgBeginPath(this->context);
					{
						/*
						 * Begin
						 */
						nvgMoveTo(this->context, rightXPosition - borderWidth, bottomYPosition - borderWidth);
						/*
						 * Top line
						 */
						nvgLineTo(this->context, leftXPosition, bottomYPosition - borderWidth);
						/*
						 * Left line
						 */
						nvgLineTo(this->context, leftXPosition, bottomYPosition);
						/*
						 * Bottom line
						 */
						nvgLineTo(this->context, rightXPosition, bottomYPosition);
						/*
						 * Right line
						 */
						nvgLineTo(this->context, rightXPosition - borderWidth, bottomYPosition - borderWidth);
					}
					nvgClosePath(this->context);
					nvgFill(this->context);

					/*
					 * Left
					 */
					nvgFillColor(this->context, Tools::Colors::cduSettableBorderLeftGray);
					nvgBeginPath(this->context);
					{
						/*
						 * Begin
						 */
						nvgMoveTo(this->context, leftXPosition, topYPosition);
						/*
						 * Top line
						 */
						nvgLineTo(this->context, leftXPosition + borderWidth, topYPosition + borderWidth);
						/*
						 * Left line
						 */
						nvgLineTo(this->context, leftXPosition + borderWidth, bottomYPosition - borderWidth);
						/*
						 * Bottom line
						 */
						nvgLineTo(this->context, leftXPosition, bottomYPosition);
						/*
						 * Right line
						 */
						nvgLineTo(this->context, leftXPosition, topYPosition);
					}
					nvgClosePath(this->context);
					nvgFill(this->context);
				}
			}

			nvgBeginPath(this->context);
			{
				for (int i = dataSize - 1; i >= 0; i--) {
					const std::string character = std::get<0>(data.at(i));
					nvgFontSize(this->context, std::get<3>(data.at(i)));
					nvgTextBounds(this->context, lastBounds[0], 0, character.c_str(), nullptr, nextBounds);
					const auto color = std::get<1>(data.at(i));
					nvgFillColor(this->context, color);
					nvgText(this->context, lastBounds[0], 0, character.c_str(), nullptr);
					lastBounds[0] = nextBounds[0];
					lastBounds[1] = nextBounds[1];
					lastBounds[2] = nextBounds[2];
					lastBounds[3] = nextBounds[3];
				}
			}
			nvgClosePath(this->context);
			nvgFill(this->context);
		}
		nvgResetTransform(this->context);
	}
	nvgRestore(this->context);
}

auto CDULineRenderer::getVerticalOffset() -> float {
	return CDULineRenderer::baseVerticalOffset + CDULineRenderer::yOffsetFactor * static_cast<float>(this->lineNumber) +
			(this->lineType == CDULineType::TITLE ? CDULineRenderer::titleVerticalOffset : 0);
}

auto CDULineRenderer::prepareContent(const std::vector<std::vector<std::string>>& content) -> void {
	for (int i = 0; i < content.size(); i++) {
		const auto contentPart = content.at(i)[0];
		const auto contentC = contentPart.c_str();
		const auto contentCSize = strlen(contentC);
		for (size_t j = 0; j < contentCSize;) {
			int numberOfOctet;
			//
			// Checking how much octets character uses (support for UTF8)
			//
			if ((contentC[j] & 0x80) == 0) {
				// character is 1 octet long
				numberOfOctet = 1;
			}
			else if ((contentC[j] & 0xE0) == 0xC0) {
				// character is 2 octet long
				numberOfOctet = 2;
			}
			else if ((contentC[j] & 0xF0) == 0xE0) {
				// character is 3 octet long
				numberOfOctet = 3;
			}
			else if ((contentC[j] & 0xF8) == 0xF0) {
				// character is 4 octet long
				numberOfOctet = 4;
			}
			else {
				numberOfOctet = 1;
			}

			const size_t shiftPosition = j + numberOfOctet;

			const std::string character = contentPart.substr(j, numberOfOctet);
			this->plainContentData += character;
			NVGcolor color = Tools::Colors::white;
			auto internalSettable = false;

			if (content.at(i)[1].find("cgreen") != std::string::npos) {
				color = Tools::Colors::greenBoeing;
			}
			else if (content.at(i)[1].find("cmagenta") != std::string::npos) {
				color = Tools::Colors::magentaBoeing;
			}
			else if (content.at(i)[1].find("cred") != std::string::npos) {
				color = Tools::Colors::red;
			}
			else if (content.at(i)[1].find("cblue") != std::string::npos) {
				color = Tools::Colors::blue;
			}
			else if (content.at(i)[1].find("cwhite") != std::string::npos) {
				color = Tools::Colors::white;
			}
			else if (content.at(i)[1].find("cblack") != std::string::npos) {
				color = Tools::Colors::black;
			}

			if (content.at(i)[1].find("settable") != std::string::npos) {
				internalSettable = true;
			}
			else {
				internalSettable = false;
			}

			float fontSize = this->fontSize;

			if(content.at(i)[1].find("ssmall") != std::string::npos) {
				fontSize = fontSize / 1.3;
			}

			this->complexContentData.push_back(std::tuple<std::string, NVGcolor, bool, float>(character, color,
				                                   internalSettable, fontSize));
			j = shiftPosition;
		}
	}
}

auto CDULineRenderer::clearData() -> void {
	this->complexContentData.clear();
	this->plainContentData.clear();
}

auto CDULineRenderer::calculateHorizontalOffset() -> void {
	nvgFontSize(this->context, this->fontSize);
	nvgTextAlign(this->context, NVG_ALIGN_RIGHT | NVG_ALIGN_MIDDLE);
	float translateXBounds[4];
	nvgTextBounds(this->context, 0, 0, this->plainContentData.c_str(), nullptr, translateXBounds);
	switch (this->lineAlign) {

		case CDULineAlign::LEFT: {
			this->horizontalOffset = 10 + (translateXBounds[2] - translateXBounds[0]);
		}
		break;
		case CDULineAlign::CENTER_LEFT: {
			this->horizontalOffset = 0;
		}
		break;
		case CDULineAlign::CENTER: {
			this->horizontalOffset = 249 + ((translateXBounds[2] - translateXBounds[0]) / 2);
		}
		break;
		case CDULineAlign::CENTER_RIGHT: {
			this->horizontalOffset = 0;
		}
		break;
		case CDULineAlign::RIGHT: {
			this->horizontalOffset = 488;
		}
		break;
		default: {
			this->horizontalOffset = 10 + (translateXBounds[2] - translateXBounds[0]);
		}
	}
}
