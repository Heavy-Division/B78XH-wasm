// #include "BatteryRepository.h"
//
// using namespace units::voltage;
// using namespace units::current;
// using namespace units::power;
// using namespace units::literals;
//
// auto BatteryRepository::isDischarging() -> bool {
//     return false;
// }
//
// auto BatteryRepository::getCurrent() -> units::current::ampere_t {
//     return static_cast<ampere_t>(0.);
// }
//
// auto BatteryRepository::getOutputPotential() -> units::voltage::volt_t {
//     return static_cast<volt_t>(0.);
// }
//
// auto BatteryRepository::getInputPotential() -> units::voltage::volt_t {
//     return static_cast<volt_t>(0.);
// }
//
// auto BatteryRepository::getPower() -> units::power::watt_t {
//     return getCurrent() * getOutputPotential();
// };
