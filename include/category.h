/**
 * Category class.
 * 
 * @author Alessio Checchin
*/

#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>

namespace prj
{

/**
 * Category class.
*/
class category
{
public:
	/**
	 * Category constructor.
	*/
	category(const std::string& name, unsigned int id);

	/**
	 * Name getter.
	 * @return The name of the category.
	*/
	std::string get_name() const;

	/**
	 * Id getter.
	 * @return The id of the category.
	*/
	unsigned int get_id() const;

private:
	/**
	 * Category name.
	*/
	std::string name_;

	/**
	 * Category id.
	*/
	unsigned int id_;
};

} // prj

#endif // CATEGORY_H