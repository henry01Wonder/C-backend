<script setup>
import { onMounted, onUnmounted, ref } from 'vue';
let count = ref(0);
let scheduleId;
onMounted(() => {
    scheduleId = window.setInterval(() => {
        count.value++;
        console.log("定時加1");
    }, 1000);
})


onUnmounted(() => {
    window.clearInterval(scheduleId);
    console.log("清除定時器")
})
defineProps(["color", "backgroundColor"]);
let text = ref("網站上的內容");
let change = function () {
    text.value = "新的網站內容";
}
let emit = defineEmits(["update"]);
let updateParentSubtitle = function () {
    emit("update");
}          
</script>
<template>
    <div>{{ count }}</div>
    <main :style="{ color: color, backgroundColor: backgroundColor }">
        <div @click="change">{{ text }}</div>
        <!-- <button @click="$emit('update')">改變副標題</button> -->
        <button @click="updateParentSubtitle">改變副標題</button>
    </main>
</template>
<style scope>
main {
    padding: 10px;
    background-color: #dddddd;
}
</style>
