#ifndef DESCARTES_LIGHT_TESSERACT_COLLISION_CHECKER_H
#define DESCARTES_LIGHT_TESSERACT_COLLISION_CHECKER_H

#include <memory>
#include <descartes_light/core/collision_interface.h>
#include <tesseract_core/basic_env.h>

namespace descartes_light
{

class TesseractCollision : public CollisionInterface
{
public:
  /**
   * @brief TesseractCollision
   * @param collision_env The collision Environment
   * @param active_links The list of active links
   * @param joint_names The list of joint names in the order that the data will be provided to the validate function.
   */
  TesseractCollision(tesseract::BasicEnvConstPtr collision_env,
                     const std::vector<std::string>& active_links,
                     const std::vector<std::string>& joint_names);

  bool validate(const double* pos, std::size_t size) override;

  std::shared_ptr<CollisionInterface> clone() const override;

  tesseract::BasicEnvConstPtr& environment() { return collision_env_; }
  const tesseract::BasicEnvConstPtr& environment() const { return collision_env_; }

private:
  bool isContactAllowed(const std::string& a, const std::string& b) const;

  tesseract::BasicEnvConstPtr collision_env_;
  std::vector<std::string> active_link_names_;
  std::vector<std::string> joint_names_;
  tesseract::DiscreteContactManagerBasePtr contact_manager_;
};

}

#endif
