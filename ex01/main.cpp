# include "Serializer.hpp"

int	main()
{
	Data*		data.content = "hello";
	uintptr_t	num;

	num = Serializer::serialize(data);
	data = Serialize::deserialize(num);
}
