#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo "🧹 Cleaning previous build..."
if xmake clean; then
    echo -e "${GREEN}Clean successful${NC}"
else
    echo -e "${RED}Clean failed${NC}"
    exit 1
fi

echo "🔨 Building project..."
if xmake; then
    echo -e "${GREEN}Build successful${NC}"
else
    echo -e "${RED}Build failed${NC}"
    exit 1
fi

echo "🧪 Running tests..."
if xmake run tests; then
    echo -e "${GREEN}All tests passed${NC}"
    exit 0
else
    echo -e "${RED}Tests failed${NC}"
    exit 1
fi