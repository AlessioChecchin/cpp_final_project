#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <memory>

namespace prj
{

class building
{
public:

	building(const building& b) = delete;
	building& operator=(const building& b) = delete;

	std::string get_name() const
	{
		return name_;
	}

	unsigned int get_id() const
	{
		return id_;
	}

	virtual std::unique_ptr<building> upgrade() const = 0;
	
private:
	std::string name_;
	unsigned int id_;
};

}

#endif // BUILDING_H