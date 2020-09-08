/*
	Bedtest libraries for games
	Copyright © 2020 Arves100.

	Project: Common
	File: Cache.hpp
	Desc: Implementation of a small cache
*/
#ifndef COMMON_CACHE_HPP
#define COMMON_CACHE_HPP
#pragma once

#include <map>
#include <memory>
#include <vector>


namespace ElementTypes
{
	enum : uint64_t
	{
		None = 0,
		Library = 1,
	};
}

class CElement
{
	typedef std::map<uint64_t, void*> TElementMap;

public:
	CElement();
	virtual ~CElement();

	virtual uint64_t GetType();

	void Destroy();
	void Add(uint64_t nId, void* pData);
	void Remove(uint64_t nId);
	void* Get(uint64_t nId);

private:
	virtual void DestroyObject(std::pair<uint64_t, void*> it);

	TElementMap m_vecData;
};

class CLibraryElement : public CElement
{
	uint64_t GetType() override;

private:
	void DestroyObject(std::pair<uint64_t, void*> it) override;
};

class CCache
{
public:
	CCache();
	virtual ~CCache();

	void Destroy();

	void* GetElement(uint64_t nCacheId, uint64_t nElementId);
	CElement* Get(uint64_t nCacheId);

	void Add(uint64_t nId, CElement* pElem);

	static std::shared_ptr<CCache> Instance(); // Singleton

private:
	std::map<uint64_t, CElement*> m_mapCaches;

	static std::shared_ptr<CCache> m_pInstance;
};

#endif // COMMON_CACHE_HPP
