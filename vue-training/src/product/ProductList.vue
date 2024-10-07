<script setup>
defineProps(["products"]);
</script>

<template>
    <div class="list">
        <div class="product" v-for="product in products">
            <div class="name">{{ product.name }}</div>
            <div class="description">{{ product.description }}</div>
            <div class="price">價格: {{ product.price }}</div>
        </div>
    </div>
</template>

<style scoped>
.list {
    line-height: 1.5rem;
}

.product {
    padding: 15px 0px;
    border-bottom: 1px solid #226aad;
}

.product>.name {
    font-weight: bold;
}
</style>