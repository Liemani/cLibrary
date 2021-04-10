#ifndef T_PAIR_H
#define T_PAIR_H



typedef struct		s_Pair
{
	void			(*freeSelf)(t_pair **pair);
	void			(*descriptionSelf)(t_pair **pair);
	void			(*freeKey)(void	**key);
	void			(*descriptionKey)(void *key);
	void			(*freeValue)(void **value);
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
