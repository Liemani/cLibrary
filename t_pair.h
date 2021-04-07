#ifndef T_PAIR_H
#define T_PAIR_H



typedef struct		s_Pair
{
	void			(*freeKey)(void	**key);
	void			(*freeValue)(void **value);
	void			(*descriptionKey)(void *key);
	void			(*descriptionValue)(void *value);
}					t_Pair

typedef struct		s_pair
{
	void			*key;
	void			*value;
}					t_pair



t_Pair	Pair;

void	setPair(void (*freeKey)(void **),
		void (*freeValue)(void **),
		void (*descriptionKey)(void *),
		void (*descriptionValue)(void *));

t_pair	*newPair(void *key, void *value);
void	freePair(t_pair **pair);
void	descriptionPair(t_pair *pair);



#endif
